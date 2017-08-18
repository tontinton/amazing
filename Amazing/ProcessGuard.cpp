#include "ProcessGuard.h"
#include "WinApiException.h"
#include <string>

ProcessGuard::ProcessGuard(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId)
	: m_handle(OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId))
{
	if (!m_handle) {
		throw WinApiException("Opening process failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

ProcessGuard::~ProcessGuard()
{
	CloseHandle(m_handle);
}

HANDLE ProcessGuard::operator*() const
{
	return m_handle;
}
