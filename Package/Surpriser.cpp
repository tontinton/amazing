#include "Surpriser.h"
#include "Interfaces.h"
#include "WinApiException.h"
#include "AmazingException.h"
#include "LoggerHelper.h"
#include "InterfaceHooker.h"
#include "IHooker.h"

#ifndef NO_BUNNY_HOP
#include "CreateMoveHooker.h"
#endif

#ifndef NO_GLOWER
#include "DoPostScreenEffectsHooker.h"
#endif


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
	try {
		m_logger.success("Starting the surprise flow");

		auto modules = std::vector<std::string>{ "client.dll", "engine.dll" };
		waitForModules(modules, MODULES_SLEEP_TIME, MODULES_TIMEOUT);
		m_logger.success("The modules have loaded");

		Interfaces::init();
		m_logger.success("The interfaces have been initialized");

        NetvarSys::Get().Initialize();
        m_logger.success("Netvars have been initialized");

#ifndef NO_BUNNY_HOP
		auto& createMoveHooker = CreateMoveHooker::getInstance();
		createMoveHooker.hook();
		m_logger.success("Hooked the CreateMove() function");
#endif

#ifndef NO_GLOWER
		auto& doPostScreenEffectsHooker = DoPostScreenEffectsHooker::getInstance();
		doPostScreenEffectsHooker.hook();
		m_logger.success("Hooked the DoPostScreenEffects() function");
#endif
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
