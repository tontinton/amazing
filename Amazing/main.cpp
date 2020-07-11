#include <memory>
#include "ErrorCodes.h"
#include "ColorConsoleLogger.h"
#include "IInjector.h"
#include "DllInjector.h"
#include "AmazingException.h"
#include "WinApiException.h"
#include <filesystem>


int main(void)
{
	auto& logger = ColorConsoleLogger::getInstance();

	try {
		std::unique_ptr<IInjector> injector = std::make_unique<DllInjector>("csgo.exe");
		const auto& packagePath = std::filesystem::current_path() / "Package.dll";
		injector->inject(packagePath.string());
	}
	catch (const WinApiException& exception) {
		logger.error(exception.what());
		return ERROR_WINAPI_EXCEPTION;
	}
	catch (const AmazingException& exception) {
		logger.error(exception.what());
		return ERROR_DELIVERY_EXCEPTION;
	}
	catch (...) {
		logger.error("An exception occurred without a check");
		return ERROR_UNKNOWN_EXCEPTION;
	}

	logger.success("Everything worked :)");
	return PROGRAM_SUCCESS;
}
