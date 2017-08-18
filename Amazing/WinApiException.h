#pragma once
#include "DeliveryException.h"

class WinApiException : public std::runtime_error
{
public:
	explicit WinApiException(const std::string& message);
};
