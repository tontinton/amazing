#pragma once
#include <stdexcept>

class WinApiException : public std::runtime_error
{
public:
	explicit WinApiException(const std::string& message);
};
