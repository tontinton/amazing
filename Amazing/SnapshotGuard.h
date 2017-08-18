#pragma once
#include <windows.h>

class SnapshotGuard
{
public:
	explicit SnapshotGuard(DWORD dwFlags, DWORD th32ProcessID);
	~SnapshotGuard();

	SnapshotGuard(SnapshotGuard const&) = delete;
	void operator=(SnapshotGuard const&) = delete;

	HANDLE operator*() const;

private:
	HANDLE m_handle;
};
