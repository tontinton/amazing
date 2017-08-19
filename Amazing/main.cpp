#include <memory>
#include "ErrorCodes.h"
#include "ColorConsoleLogger.h"
#include "IInjector.h"
#include "DllInjector.h"
#include "DeliveryException.h"
#include "WinApiException.h"


int main(void)
{
	auto& logger = ColorConsoleLogger::getInstance();

	try {
		std::unique_ptr<IInjector> injector = std::make_unique<DllInjector>("python.exe");
		injector->inject("C:\\Users\\Tony Solomonik\\Documents\\visual studio 2015\\Projects\\Amazing\\Debug\\Package.dll");
	}
	catch (const WinApiException& exception) {
		logger.error(exception.what());
		return ERROR_WINAPI_EXCEPTION;
	}
	catch (const DeliveryException& exception) {
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
