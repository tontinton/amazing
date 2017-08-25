#include "MemoryProtectGuard.h"
#include "WinApiException.h"
#include "ConsoleLogger.h"

MemoryProtectGuard::MemoryProtectGuard(void* address, SIZE_T length, DWORD newProtect)
    : m_address(address),
      m_length(length),
      m_logger(ConsoleLogger::getInstance())
{
    if (!VirtualProtect(address, length, newProtect, &m_oldProtect)) {
        throw WinApiException("Changing the permission of a memory has failed");
    }
}

MemoryProtectGuard::~MemoryProtectGuard()
{
    DWORD dummy = 0;
    if (!VirtualProtect(m_address, m_length, m_oldProtect, &dummy)) {
        m_logger.warning("Reverting the permissions of a memory back has failed with error code: " + std::to_string(GetLastError()));
    }
}
