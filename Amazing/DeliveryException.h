#pragma once
#include <stdexcept>

class DeliveryException : public std::runtime_error
{
public:
	explicit DeliveryException(const std::string& message);
};
