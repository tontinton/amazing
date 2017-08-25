#include "LoggerHelper.h"


constexpr unsigned int MESSAGE_BUFFER_SIZE = 256;
constexpr LPCVOID MAKE_OUTPUT_BUFFER_SIZE = nullptr;
constexpr va_list* NO_ARGUMENTS = nullptr;


std::string LoggerHelper::GetErrorMessage(DWORD errorMessage)
{
    char messageBuffer[MESSAGE_BUFFER_SIZE];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
                  MAKE_OUTPUT_BUFFER_SIZE,
                  errorMessage,
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  messageBuffer,
                  MESSAGE_BUFFER_SIZE,
                  NO_ARGUMENTS);

    return std::string(messageBuffer);
}
