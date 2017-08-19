#include "RemoteThreadGuard.h"
#include "WinApiException.h"
#include <string>
#include "ColorConsoleLogger.h"

RemoteThreadGuard::RemoteThreadGuard(HANDLE hProcess,
                                     LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                     SIZE_T dwStackSize,
                                     LPTHREAD_START_ROUTINE lpStartAddress,
                                     LPVOID lpParameter,
                                     DWORD dwCreationFlags,
                                     LPDWORD lpThreadId)
	: m_remoteThread(CreateRemoteThread(hProcess,
	                                    lpThreadAttributes,
	                                    dwStackSize,
	                                    lpStartAddress,
	                                    lpParameter,
	                                    dwCreationFlags,
	                                    lpThreadId)),
	  m_logger(ColorConsoleLogger::getInstance())
{
	if (!m_remoteThread) {
		throw WinApiException("Creating remote thread failed with error code: " + std::to_string(GetLastError()));
	}
}

RemoteThreadGuard::~RemoteThreadGuard()
{
	if (!CloseHandle(m_remoteThread)) {
		m_logger.warning("Closing the handle of a remote thread failed with error code: " + std::to_string(GetLastError()));
	}
}

HANDLE RemoteThreadGuard::operator*() const
{
	return m_remoteThread;
}
