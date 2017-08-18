#pragma once
#include "ILogger.h"
#include <windows.h>

class ColorConsoleLogger : public ILogger
{
public:
	ColorConsoleLogger(ColorConsoleLogger const&) = delete;
	void operator=(ColorConsoleLogger const&) = delete;
	
	static ILogger& getInstance();


	void changeColor(BYTE color);
	static void print(const std::string& message);


	void success(const std::string& message) override;
	void log(const std::string& message) override;
	void warning(const std::string& message) override;
	void error(const std::string& message) override;

private:
	ColorConsoleLogger();

	BOOL m_colorSupported;
	BYTE m_currentColor;
	CONSOLE_SCREEN_BUFFER_INFO m_settings;
	HANDLE m_stdout;
};
