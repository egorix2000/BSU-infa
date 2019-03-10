#undef UNICODE
#include <windows.h>
#include <cmath>
#include <ctime>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Window creation";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	srand(time(NULL));
	MSG msg;
	if (!hPrevInstance) {
		if (!InitApplication(hInstance))
			return (FALSE);
	}

	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance) {
	WNDCLASS  wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hbrBackground = (HBRUSH)(HOLLOW_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	return RegisterClass(&wc);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		szTitle,             // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT,       // горизонтальная координата окна
		CW_USEDEFAULT,       // вертикальная координата окна
		CW_USEDEFAULT,       // ширина окна
		CW_USEDEFAULT,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

	if (!hWnd)    return (FALSE);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	INT n = 20;
	COLORREF startColor;
	RECT clientRect;
	RECT currentRect;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &clientRect);
		startColor = RGB(rand() % 255, rand() % 255, rand() % 255);

		SetRect(&currentRect, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
		
		for (INT i = 0; i < n; i++) {
			SelectObject(hDC, CreateSolidBrush(

				RGB(GetRValue(startColor) + i * (255 - GetRValue(startColor)) / (n),
					GetGValue(startColor) + i * (255 - GetGValue(startColor)) / (n),
					GetBValue(startColor) + i * (255 - GetBValue(startColor)) / (n))));
			FillRect(hDC, &currentRect, NULL);
			SetRect(&currentRect, 
				currentRect.left + clientRect.right / (2 * n), 
				currentRect.top + clientRect.bottom / (2 * n),
				currentRect.right - clientRect.right / (2 * n),
				currentRect.bottom - clientRect.bottom / (2 * n));
			DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		}
		


		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
