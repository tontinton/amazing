#pragma once
#include <windows.h>
#include "ILogger.h"

class ProcessGuard
{
public:
	ProcessGuard(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);
	~ProcessGuard();

	ProcessGuard(ProcessGuard const&) = delete;
	void operator=(ProcessGuard const&) = delete;

	HANDLE operator*() const;

private:
	HANDLE m_handle;

	ILogger& m_logger;
};
