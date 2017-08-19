#pragma once
#include <windows.h>
#include "ILogger.h"

class RemoteThreadGuard
{
public:
	RemoteThreadGuard(HANDLE hProcess,
	                           LPSECURITY_ATTRIBUTES lpThreadAttributes,
	                           SIZE_T dwStackSize,
	                           LPTHREAD_START_ROUTINE lpStartAddress,
	                           LPVOID lpParameter,
	                           DWORD dwCreationFlags,
	                           LPDWORD lpThreadId);
	~RemoteThreadGuard();

	RemoteThreadGuard(RemoteThreadGuard const&) = delete;
	void operator=(RemoteThreadGuard const&) = delete;

	HANDLE operator*() const;

private:
	HANDLE m_remoteThread;

	ILogger& m_logger;
};
