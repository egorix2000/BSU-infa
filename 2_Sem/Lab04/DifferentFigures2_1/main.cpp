#undef UNICODE
#include <windows.h>
#include <cmath>

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

	RECT clientRect;

	RECT ellipseRect;
	RECT rectangleRect;
	RECT sectorRect;
	RECT rhombusRect;
	POINT rhombusPoints[4];

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		SetBkMode(hDC, TRANSPARENT);
		GetClientRect(hwnd, &clientRect);
		SetRect(&ellipseRect, clientRect.left, clientRect.top, clientRect.right / 2, clientRect.bottom / 2);
		SetRect(&rectangleRect, clientRect.right / 2, clientRect.top, clientRect.right, clientRect.bottom / 2);
		SetRect(&sectorRect, clientRect.left, clientRect.bottom / 2, clientRect.right / 2, clientRect.bottom);
		SetRect(&rhombusRect, clientRect.right / 2, clientRect.bottom / 2, clientRect.right, clientRect.bottom);

		MoveToEx(hDC, 0, clientRect.bottom / 2, nullptr);
		LineTo(hDC, clientRect.right, clientRect.bottom / 2);
		MoveToEx(hDC, clientRect.right / 2, 0, nullptr);
		LineTo(hDC, clientRect.right / 2, clientRect.bottom);

		SelectObject(hDC, CreatePen(PS_DOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Ellipse(hDC, ellipseRect.left + 10, ellipseRect.top + 10, ellipseRect.right - 10, ellipseRect.bottom - 50);
		DrawText(hDC, "Ellipse", -1, &ellipseRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_DASH, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Rectangle(hDC, rectangleRect.left + 10, rectangleRect.top + 10, rectangleRect.right - 10, rectangleRect.bottom - 50);
		DrawText(hDC, "Rectangle", -1, &rectangleRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_DASHDOTDOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Pie(hDC, sectorRect.left + 10, sectorRect.top + 10, sectorRect.right - 10, sectorRect.bottom - 50,
			sectorRect.right - 10, 
			sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2,
			sectorRect.left + (sectorRect.right - sectorRect.left) / 2 + (sectorRect.right - sectorRect.left - 20)*sqrt(3)/4,
			sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2 - (sectorRect.right - sectorRect.left - 20) / 4);
		DrawText(hDC, "Sector", -1, &sectorRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_SOLID, 3, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		rhombusPoints[0] = { rhombusRect.left + 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
		rhombusPoints[1] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.top + 10 };
		rhombusPoints[2] = { rhombusRect.right - 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
		rhombusPoints[3] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.bottom - 50 };
		Polygon(hDC, rhombusPoints, 4);
		DrawText(hDC, "Rhombus", -1, &rhombusRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));

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
