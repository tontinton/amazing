#pragma once
#include <windows.h>
#include "ILogger.h"

class MemoryProtectGuard
{
public:
    explicit MemoryProtectGuard(void* address, SIZE_T length, DWORD newProtect);
    ~MemoryProtectGuard();

    MemoryProtectGuard(MemoryProtectGuard const&) = delete;
    void operator=(MemoryProtectGuard const&) = delete;

private:
    void* m_address;
    SIZE_T m_length;
    DWORD m_oldProtect;

    ILogger& m_logger;
};
