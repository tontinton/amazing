#include "Surpriser.h"
#include "Interfaces.h"
#include "WinApiException.h"
#include "AmazingException.h"
#include "LoggerHelper.h"


constexpr DWORD MODULES_SLEEP_TIME = 1000;
constexpr DWORD MODULES_TIMEOUT = 15000;


Surpriser::Surpriser(ILogger& logger)
    : m_logger(logger) {}


void Surpriser::waitForModules(const std::vector<std::string>& modules, DWORD sleep, DWORD timeout)
{
    DWORD totalSleptTime = 0;

    while (totalSleptTime < timeout) {
        auto allModulesHaveLoaded = true;
        for (auto&& module : modules) {
            if (!GetModuleHandle(module.c_str())) {
                allModulesHaveLoaded = false;
                break;
            }
        }

        if (allModulesHaveLoaded) {
            return;
        }

        Sleep(sleep);
        totalSleptTime += sleep;
    }

    throw AmazingException("Waiting for modules has failed");
}


void Surpriser::start() const
{
    m_logger.success("Starting the surprise flow");

    auto modules = std::vector<std::string>{"client.dll", "engine.dll"};
    waitForModules(modules, MODULES_SLEEP_TIME, MODULES_TIMEOUT);
    m_logger.success("The modules have loaded");

    try {
        Interfaces::init();
        m_logger.success("The interfaces have been initialized");
    }
    catch (const WinApiException& exception) {
        auto lastError = GetLastError();
        auto message = std::string(exception.what())
            + ", Error: "
            + std::to_string(lastError)
            + ", Message: "
            + LoggerHelper::GetErrorMessage(lastError);
        m_logger.error(message);

        return;
    }
    catch (const AmazingException& exception) {
        m_logger.error(exception.what());
        return;
    }
    catch (...) {
        m_logger.error("Unknown exception");
        return;
    }

    m_logger.success("Everything worked :)");
}
