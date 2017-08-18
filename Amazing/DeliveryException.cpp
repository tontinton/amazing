#include "DeliveryException.h"

DeliveryException::DeliveryException(const std::string& message)
	: runtime_error(message) {}
