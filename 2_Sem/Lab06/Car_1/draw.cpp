#include "draw.h"

BOOL DrawBitmap(HDC &hDC, INT x, INT y, INT width, INT height, HBITMAP hBitmap, DWORD dwROP)
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