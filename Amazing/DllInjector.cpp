#include "DllInjector.h"
#include <windows.h>
#include <TlHelp32.h>
#include "DeliveryException.h"
#include "WinApiException.h"
#include "SnapshotGuard.h"
#include "ProcessGuard.h"
#include "ColorConsoleLogger.h"


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
		throw DeliveryException("Could not find the process: " + processName);
	}
	m_logger.success("Found the process: " + processName + ", with PID of: " + std::to_string(processStruct.th32ProcessID));

	m_processId = processStruct.th32ProcessID;
}

void DllInjector::inject(const std::string& path)
{
	ProcessGuard remoteProcess(PROCESS_ALL_ACCESS, FALSE, m_processId);
	path;
}
