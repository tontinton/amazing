#pragma once

#include <string>

class ILogger
{
public:
	virtual ~ILogger() = default;

	virtual void success(const std::string& message) = 0;
	virtual void log(const std::string& message) = 0;
	virtual void warning(const std::string& message) = 0;
	virtual void error(const std::string& message) = 0;
};
