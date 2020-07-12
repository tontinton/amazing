#pragma once
#include <windows.h>
#include "ILogger.h"

template<size_t Size>
class RemotePatchGuard
{
public:
	RemotePatchGuard(HANDLE process, LPVOID remoteAddress, char(&patchBytes)[Size]);
	~RemotePatchGuard();

	RemotePatchGuard(RemotePatchGuard const&) = delete;
	void operator=(RemotePatchGuard const&) = delete;

private:
	HANDLE m_process;
	LPVOID m_remoteAddress;
	char m_originalBytes[Size]{};
	ILogger& m_logger;
};

template<size_t Size>
RemotePatchGuard<Size>::RemotePatchGuard(HANDLE process, LPVOID remoteAddress, char(&patchBytes)[Size])
	: m_process(process),
	m_remoteAddress(remoteAddress),
	m_logger(ColorConsoleLogger::getInstance())
{
	SIZE_T numberOfBytes = 0;
	if (!ReadProcessMemory(m_process, remoteAddress, m_originalBytes, Size, &numberOfBytes) ||
		Size != numberOfBytes) {

		throw WinApiException("Reading original bytes failed with error code: " + std::to_string(GetLastError()));
	}

	if (!WriteProcessMemory(m_process, remoteAddress, patchBytes, Size, &numberOfBytes) ||
		Size != numberOfBytes) {

		throw WinApiException("Writing patch failed with error code: " + std::to_string(GetLastError()));
	}
}

template<size_t Size>
RemotePatchGuard<Size>::~RemotePatchGuard()
{
	SIZE_T numberOfBytes = 0;
	if (!WriteProcessMemory(m_process, m_remoteAddress, m_originalBytes, Size, &numberOfBytes) ||
		Size != numberOfBytes) {

		m_logger.warning("Writing original bytes failed in patch guard with error code: " + std::to_string(GetLastError()));
	}
}
