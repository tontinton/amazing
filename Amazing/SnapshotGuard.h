#pragma once
#include <windows.h>
#include "ILogger.h"

class SnapshotGuard
{
public:
	SnapshotGuard(DWORD dwFlags, DWORD th32ProcessID);
	~SnapshotGuard();

	SnapshotGuard(SnapshotGuard const&) = delete;
	void operator=(SnapshotGuard const&) = delete;

	HANDLE operator*() const;

private:
	HANDLE m_handle;

	ILogger& m_logger;
};
