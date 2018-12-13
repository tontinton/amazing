#include "RemoteMemoryGuard.h"
#include "WinApiException.h"
#include <string>
#include "ColorConsoleLogger.h"


RemoteMemoryGuard::RemoteMemoryGuard(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
	: m_remoteAddress(VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, PAGE_NOACCESS)),
	  m_process(hProcess),
	  m_memorySize(dwSize),
	  m_logger(ColorConsoleLogger::getInstance())

{
	if (!m_remoteAddress) {
		throw WinApiException("Allocating memory in a remote process failed in guard with error code: " + std::to_string(GetLastError()));
	}
	DWORD oldProtect = 0;
	if (!VirtualProtectEx(hProcess, m_remoteAddress, dwSize, flProtect, &oldProtect)) {
		throw WinApiException("Changing protection of memory in a remote process failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

RemoteMemoryGuard::~RemoteMemoryGuard()
{
	if (!VirtualFreeEx(m_process, m_remoteAddress, 0, MEM_RELEASE)) {
		m_logger.warning("Freeing memory in remote process failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

LPVOID RemoteMemoryGuard::operator*() const
{
	return m_remoteAddress;
}

SIZE_T RemoteMemoryGuard::getSize() const
{
	return m_memorySize;
}
