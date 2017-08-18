#pragma once
#include <windows.h>

class ProcessGuard
{
public:
	explicit ProcessGuard(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);
	~ProcessGuard();

	ProcessGuard(ProcessGuard const&) = delete;
	void operator=(ProcessGuard const&) = delete;

	HANDLE operator*() const;

private:
	HANDLE m_handle;
};
