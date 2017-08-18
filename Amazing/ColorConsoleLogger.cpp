#include "ColorConsoleLogger.h"
#include <iostream>
#include <memory>


#define	SUCCESS_COLOR	0x0A
#define	REGULAR_COLOR	0x07
#define	WARNING_COLOR	0x0E
#define	ERROR_COLOR		0x0C


ColorConsoleLogger::ColorConsoleLogger()
	: m_colorSupported(TRUE),
	  m_currentColor(REGULAR_COLOR),
	  m_stdout(GetStdHandle(STD_OUTPUT_HANDLE))

{
	if (!m_stdout) {
		m_colorSupported = FALSE;
		print("Color printing is not supported in this console application. Using non colored printing");
		return;
	}

	if (!GetConsoleScreenBufferInfo(m_stdout, &m_settings)) {
		m_colorSupported = FALSE;
		print("Could not get the color setting in this color application. Using non colored printing");
	}
}


ILogger& ColorConsoleLogger::getInstance()
{
	static ColorConsoleLogger instance;
	return instance;
}


void ColorConsoleLogger::changeColor(BYTE color)
{
	if (m_colorSupported && m_currentColor != color) {
		SetConsoleTextAttribute(m_stdout, color);
		m_currentColor = color;
	}
}

void ColorConsoleLogger::print(const std::string& message)
{
	std::cout << message << std::endl;
}


void ColorConsoleLogger::success(const std::string& message)
{
	changeColor(SUCCESS_COLOR);
	print("[+] " + message);
}

void ColorConsoleLogger::log(const std::string& message)
{
	changeColor(REGULAR_COLOR);
	print("[l] " + message);
}

void ColorConsoleLogger::warning(const std::string& message)
{
	changeColor(WARNING_COLOR);
	print("[?] " + message);
}

void ColorConsoleLogger::error(const std::string& message)
{
	changeColor(ERROR_COLOR);
	print("[-] " + message);
}
