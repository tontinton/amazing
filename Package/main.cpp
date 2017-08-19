#include <windows.h>
#include "../Amazing/WinApiException.h"
#include "../Amazing/AmazingException.h"
#include "Interfaces.h"


void WINAPI openSurprise()
{
    MessageBox(NULL, "Success", "Package", MB_OK);
	try {
		Interfaces::init();
	}
	catch (const WinApiException& exception) {
		MessageBox(NULL, exception.what(), "Package", MB_OK);
	}
	catch (const AmazingException& exception) {
		MessageBox(NULL, exception.what(), "Package", MB_OK);
	}
	catch (...) {
		MessageBox(NULL, "Unkown exception", "Package", MB_OK);
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
