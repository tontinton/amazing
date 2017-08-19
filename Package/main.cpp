#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE, DWORD reason, LPVOID)
{
	if (DLL_PROCESS_ATTACH == reason) {
		MessageBox(NULL, "Success", "Package", MB_OK);
	}
	return TRUE;
}
