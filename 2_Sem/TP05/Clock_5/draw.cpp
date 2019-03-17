#include <cmath>
#include "draw.h"

void DrawClock(HDC hDC, INT x, INT y, INT width, INT height, HBITMAP hBmpClock, DWORD dwROP, 
		int seconds, int minutes) {
	DrawBitmap(hDC, x, y, width, height, hBmpClock, dwROP);

	SelectObject(hDC, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
	MoveToEx(hDC, x + width / 2, y + height / 2, nullptr);
	LineTo(hDC, (width / 2)*sin(seconds * (acos(-1) / 30)) + x + height / 2,
		-(height / 2)*cos(seconds * (acos(-1) / 30)) + y + height / 2);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));

	SelectObject(hDC, CreatePen(PS_SOLID, 4, RGB(0, 0, 0)));
	MoveToEx(hDC, x + width / 2, y + height / 2, nullptr);
	LineTo(hDC, (width / 4)*sin(minutes * (acos(-1) / 30)) + x + width / 2,
		-(height / 4)*cos(minutes * (acos(-1) / 30)) + y + height / 2);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
}

BOOL DrawBitmap(HDC hDC, INT x, INT y, INT width, INT height, HBITMAP hBitmap, DWORD dwROP)
{
	HDC hMemoryDC;
	BITMAP Bitmap;
	BOOL bResult;

	if (!hDC || !hBitmap)
		return FALSE;

	hMemoryDC = CreateCompatibleDC(hDC);
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	SelectObject(hMemoryDC, hBitmap);
	bResult = StretchBlt(hDC, x, y, width, height,
		hMemoryDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, dwROP);
	DeleteDC(hMemoryDC);

	return bResult;
}