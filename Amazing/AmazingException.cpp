#include "AmazingException.h"

AmazingException::AmazingException(const std::string& message)
	: runtime_error(message) {}
