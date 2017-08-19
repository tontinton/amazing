#pragma once
#include <windows.h>
#include "ILogger.h"

class RemoteMemoryGuard
{
public:
	explicit RemoteMemoryGuard(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
	~RemoteMemoryGuard();

	RemoteMemoryGuard(RemoteMemoryGuard const&) = delete;
	void operator=(RemoteMemoryGuard const&) = delete;

	LPVOID operator*() const;
	SIZE_T getSize() const;

private:
	LPVOID m_remoteAddress;
	HANDLE m_process;
	SIZE_T m_memorySize;

	ILogger& m_logger;
};
