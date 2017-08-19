#include "ProcessGuard.h"
#include "WinApiException.h"
#include <string>
#include "ColorConsoleLogger.h"

ProcessGuard::ProcessGuard(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId)
	: m_handle(OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId)),
	  m_logger(ColorConsoleLogger::getInstance())
{
	if (!m_handle) {
		throw WinApiException("Opening process failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

ProcessGuard::~ProcessGuard()
{
	if (!CloseHandle(m_handle)) {
		m_logger.warning("Closing the process handle failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

HANDLE ProcessGuard::operator*() const
{
	return m_handle;
}
