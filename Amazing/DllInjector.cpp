#include "DllInjector.h"
#include <windows.h>
#include <TlHelp32.h>
#include "AmazingException.h"
#include "WinApiException.h"
#include "SnapshotGuard.h"
#include "ProcessGuard.h"
#include "ColorConsoleLogger.h"
#include "RemoteMemoryGuard.h"
#include "RemoteThreadGuard.h"
#include "RemotePatchGuard.h"


LPVOID LET_WINDOWS_DECIDE_ADDRESS = NULL;

constexpr char* KERNEL_MODULE = "kernel32";
constexpr char* LOAD_LIBRARY_A = "LoadLibraryA";

constexpr char* NTDLL_MODULE = "ntdll";
constexpr char* NT_OPEN_FILE = "NtOpenFile";
constexpr size_t TRUST_MODE_HOOK_LENGTH = 5;


DllInjector::DllInjector(const std::string& processName)
	: m_logger(ColorConsoleLogger::getInstance())
{
	SnapshotGuard processes(TH32CS_SNAPPROCESS, 0);
	m_logger.success("Got processes snapshot");

	PROCESSENTRY32 processStruct = {0};
	processStruct.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(*processes, &processStruct)) {
		throw WinApiException("Getting the first process in snapshot failed with error code: " + std::to_string(GetLastError()));
	}

	auto foundProcess = FALSE;
	do {
		if (strcmp(processName.c_str(), processStruct.szExeFile) == 0) {
			foundProcess = TRUE;
			break;
		}
	}
	while (Process32Next(*processes, &processStruct));

	if (!foundProcess) {
		throw AmazingException("Could not find the process: " + processName);
	}
	m_logger.success("Found the process: " + processName + ", with PID of: " + std::to_string(processStruct.th32ProcessID));

	m_processId = processStruct.th32ProcessID;
}

void DllInjector::inject(const std::string& path)
{
	ProcessGuard remoteProcess(PROCESS_ALL_ACCESS, FALSE, m_processId);
	m_logger.success("Received the remote process by it's pid");


	LPVOID ntOpenFile = GetProcAddress(LoadLibrary(TEXT(NTDLL_MODULE)), NT_OPEN_FILE);
	if (!ntOpenFile) {
		throw WinApiException("Getting address of NtOpenFile failed with error code: " + std::to_string(GetLastError()));
	}

	char preValveHookBytes[TRUST_MODE_HOOK_LENGTH];
	memcpy(preValveHookBytes, ntOpenFile, sizeof(preValveHookBytes));

	RemotePatchGuard trustModePatch(*remoteProcess, ntOpenFile, preValveHookBytes);
	m_logger.success("Patched trust mode in the remote process");


	auto pathBuffer = path.c_str();
	auto pathSize = strlen(pathBuffer) + 1;

	RemoteMemoryGuard remoteMemory(*remoteProcess, LET_WINDOWS_DECIDE_ADDRESS, pathSize, MEM_COMMIT, PAGE_READWRITE);
	m_logger.success("Allocated memory in the remote process: " + std::to_string(reinterpret_cast<size_t>(*remoteMemory)));


	SIZE_T numberOfBytesWritten = 0;
	if (!WriteProcessMemory(*remoteProcess, *remoteMemory, pathBuffer, pathSize, &numberOfBytesWritten) ||
		pathSize != numberOfBytesWritten) {

		throw WinApiException("Writing the library's path to the remote process failed with error code: " + std::to_string(GetLastError()));
	}
	m_logger.success("Wrote the dll path to the remote process: " + path);


	auto kernelModule = GetModuleHandle(KERNEL_MODULE);
	if (!kernelModule) {
		throw WinApiException("Getting the kernel module handle failed with error code: " + std::to_string(GetLastError()));
	}
	m_logger.success("Got the kernel module handle");


	auto loadLibraryAddress = GetProcAddress(kernelModule, LOAD_LIBRARY_A);
	if (!loadLibraryAddress) {
		throw WinApiException("Getting the address of the load library function failed with error code: " + std::to_string(GetLastError()));
	}
	m_logger.success("Got the address of the load library function");


	RemoteThreadGuard remoteThread(*remoteProcess,
	                               NULL, // Default thread security attributes
	                               0, // Default stack size
	                               reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibraryAddress),
	                               *remoteMemory,
	                               0, // Run immediatly after creation
	                               NULL); // Don't care about the thread ID
	m_logger.success("Created a remote thread that executes load library");


	if (WaitForSingleObject(*remoteThread, INFINITE)) {
		throw WinApiException("Waiting for remote thread to return failed with error code: " + std::to_string(GetLastError()));
	}

	DWORD exitCode = 0;
	if (!GetExitCodeThread(*remoteThread, &exitCode)) {
		throw WinApiException("Getting return code of thread failed with error code: " + std::to_string(GetLastError()));
	}

	if (!exitCode) {
		throw WinApiException("LoadLibrary in remote process failed");
	}
}
