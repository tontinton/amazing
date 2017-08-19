#include "SnapshotGuard.h"
#include "WinApiException.h"
#include <TlHelp32.h>
#include <string>
#include "ColorConsoleLogger.h"

SnapshotGuard::SnapshotGuard(DWORD dwFlags, DWORD th32ProcessID)
	: m_handle(CreateToolhelp32Snapshot(dwFlags, th32ProcessID)),
	m_logger(ColorConsoleLogger::getInstance())
{
	if (INVALID_HANDLE_VALUE == m_handle) {
		throw WinApiException("Creating snapshot failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

SnapshotGuard::~SnapshotGuard()
{
	if (!CloseHandle(m_handle)) {
		m_logger.warning("Closing the snapshow failed in guard with error code: " + std::to_string(GetLastError()));
	}
}
HANDLE SnapshotGuard::operator*() const
{
	return m_handle;
}
