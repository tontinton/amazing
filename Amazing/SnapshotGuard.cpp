#include "SnapshotGuard.h"
#include "WinApiException.h"
#include <TlHelp32.h>
#include <string>

SnapshotGuard::SnapshotGuard(DWORD dwFlags, DWORD th32ProcessID)
	: m_handle(CreateToolhelp32Snapshot(dwFlags, th32ProcessID))
{
	if (INVALID_HANDLE_VALUE == m_handle) {
		throw WinApiException("Creating snapshot failed in guard with error code: " + std::to_string(GetLastError()));
	}
}

SnapshotGuard::~SnapshotGuard()
{
	CloseHandle(m_handle);
}
HANDLE SnapshotGuard::operator*() const
{
	return m_handle;
}
