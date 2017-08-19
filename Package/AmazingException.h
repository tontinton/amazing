#pragma once
#include <stdexcept>

class AmazingException : public std::runtime_error
{
public:
	explicit AmazingException(const std::string& message);
};
