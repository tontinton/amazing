#pragma once
#include <string>

class IInjector
{
public:
	virtual ~IInjector() = default;

	virtual void inject(const std::string& path) = 0;
};
