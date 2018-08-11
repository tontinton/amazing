#include "ConsoleLogger.h"
#include "WinApiException.h"


HANDLE SafeGetStdHandle(DWORD handle)
{
    auto stdHandle = GetStdHandle(handle);
    if (INVALID_HANDLE_VALUE == stdHandle) {
        throw WinApiException("Getting the std handle has failed");
    }

    return stdHandle;
}

ConsoleLogger::ConsoleLogger()
{
    m_old_stdout = SafeGetStdHandle(STD_OUTPUT_HANDLE);
    m_old_stderr = SafeGetStdHandle(STD_ERROR_HANDLE);
    m_old_stdin = SafeGetStdHandle(STD_INPUT_HANDLE);

    FreeConsole();

    if (!AllocConsole()) {
        throw WinApiException("Allocating a new console has failed");
    }

    m_new_stdout = SafeGetStdHandle(STD_OUTPUT_HANDLE);
    m_new_stderr = SafeGetStdHandle(STD_ERROR_HANDLE);
    m_new_stdin = SafeGetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(m_new_stdout,
                   ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);

    SetConsoleMode(m_new_stdin,
                   ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS |
                   ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE);
}

ConsoleLogger::~ConsoleLogger()
{
    if (m_new_stdout && m_new_stderr && m_new_stdin) {
        FreeConsole();

        if (m_new_stdout) {
            SetStdHandle(STD_OUTPUT_HANDLE, m_old_stdout);
        }
        if (m_new_stderr) {
            SetStdHandle(STD_ERROR_HANDLE, m_old_stderr);
        }
        if (m_new_stdin) {
            SetStdHandle(STD_INPUT_HANDLE, m_old_stdin);
        }
    }
}

ILogger& ConsoleLogger::getInstance()
{
	static ConsoleLogger instance{};
    return instance;
}

void ConsoleLogger::print(const std::string& message) const
{
    auto buffer = message.c_str();
    WriteConsole(m_new_stdout, buffer, static_cast<DWORD>(strlen(buffer)), nullptr, nullptr);
}

void ConsoleLogger::success(const std::string& message)
{
    print("[+] " + message + "\n");
}

void ConsoleLogger::log(const std::string& message)
{
    print("[l] " + message + "\n");
}

void ConsoleLogger::warning(const std::string& message)
{
    print("[?] " + message + "\n");
}

void ConsoleLogger::error(const std::string& message)
{
    print("[-] " + message + "\n");
}
