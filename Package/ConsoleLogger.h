#pragma once
#include <windows.h>
#include "ILogger.h"


class ConsoleLogger : public ILogger
{
public:
	ConsoleLogger();
	~ConsoleLogger();

    static ILogger& getInstance();

    void printMessage(const std::string& message) const;

	void success(const std::string& message) override;
	void log(const std::string& message) override;
	void warning(const std::string& message) override;
	void error(const std::string& message) override;

private:
    HANDLE m_old_stdout;
    HANDLE m_old_stderr;
    HANDLE m_old_stdin;

    HANDLE m_new_stdout;
    HANDLE m_new_stderr;
    HANDLE m_new_stdin;
};
