#include <windows.h>
#include <D2d1.h>



#pragma comment(lib, "d2d1")

#include "MainWindow.h"

HANDLE g_hTimer = NULL;

BOOL InitializeTimer();




// Constants 
const WCHAR WINDOW_NAME [] = L"Pac Man";


INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, INT nCmdShow)
{
	if (FAILED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)))
	{
		return 0;
	}
	if (!InitializeTimer())
	{
		CoUninitialize();
		return 0;
	}

	MainWindow win;

	if (!win.Create(WINDOW_NAME, WS_OVERLAPPEDWINDOW))
	{
		return 0;
	}

	ShowWindow(win.Window(), nCmdShow);

	// Run the message loop.

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
		// Wait until the timer expires or any message is posted.
		if (MsgWaitForMultipleObjects(1, &g_hTimer, FALSE, INFINITE, QS_ALLINPUT)
			== WAIT_OBJECT_0)
		{
			InvalidateRect(win.Window(), NULL, FALSE);
		}
	}


	CloseHandle(g_hTimer);
	CoUninitialize();
	return 0;
}




BOOL InitializeTimer()
{
	g_hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (g_hTimer == NULL)
	{
		return FALSE;
	}

	LARGE_INTEGER li = { 0 };

	if (!SetWaitableTimer(g_hTimer, &li, (1000 / 60), NULL, NULL, FALSE))
	{
		CloseHandle(g_hTimer);
		g_hTimer = NULL;
		return FALSE;
	}

	return TRUE;
}

