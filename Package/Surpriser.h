#pragma once

#include <windows.h>
#include "ILogger.h"
#include <vector>


class Surpriser
{
public:
    explicit Surpriser(ILogger& logger);

    void start() const;

private:
    static void waitForModules(const std::vector<std::string>& modules, DWORD sleep, DWORD timeout);

    ILogger& m_logger;
};
