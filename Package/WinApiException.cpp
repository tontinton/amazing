#include "WinApiException.h"

WinApiException::WinApiException(const std::string& message)
	: runtime_error(message) {}
