#include <windows.h>
#include "WinApiException.h"
#include "Surpriser.h"
#include "ILogger.h"
#include "ConsoleLogger.h"
#include "LoggerHelper.h"


void WINAPI openSurprise()
{
    try {
        auto& logger = ConsoleLogger::getInstance();

        auto surpriser = Surpriser{logger};
        surpriser.start();
    }
    catch (const WinApiException& exception) {
        auto lastError = GetLastError();
        auto message = std::string(exception.what())
            + ", Error: "
            + std::to_string(lastError)
            + ", Message: "
            + LoggerHelper::GetErrorMessage(lastError);
        MessageBox(NULL, message.c_str(), "Package", MB_OK);
    } catch(...) {
        MessageBox(NULL, "Unknown Error", "Package", MB_OK);
    }
}

BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID)
{
    if (DLL_PROCESS_ATTACH == reason) {
        if (!CreateThread(NULL, // Default thread attributes
                          NULL, // Default stack size
                          reinterpret_cast<LPTHREAD_START_ROUTINE>(&openSurprise),
                          NULL, // No parameters
                          0, // Run immediatly after creation
                          NULL)) {
            return FALSE;
        }
    }
    return TRUE;
}
