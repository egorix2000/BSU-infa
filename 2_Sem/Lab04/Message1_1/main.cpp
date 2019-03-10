#include <windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR par, int)
{
	TCHAR output[50];
	sprintf_s(output, "You entered %s", par);
	MessageBox(NULL, output, "Caption", MB_OKCANCEL);
	//  start C:\WinApiLab\Lab04\Debug\Message1_1 6
	return 0;
}
