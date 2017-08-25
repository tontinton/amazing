#pragma once
#include <windows.h>
#include <string>

class LoggerHelper
{
public:
    static std::string GetErrorMessage(DWORD errorMessage);
};
