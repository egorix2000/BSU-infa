#undef UNICODE
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Window creation";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE - 1);
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
	RECT rect;
	LPCSTR helloWorld = "Hello, World!";

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		SetBkMode(hDC, TRANSPARENT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_TOP | DT_RIGHT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
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
