#pragma once
#include "IInjector.h"
#include "ILogger.h"
#include <windows.h>

class DllInjector : public IInjector
{
public:
	explicit DllInjector(const std::string& processName);

	void inject(const std::string& path) override;

private:
	ILogger& m_logger;
	DWORD m_processId;
};
