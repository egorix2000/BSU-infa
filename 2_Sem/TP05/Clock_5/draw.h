#pragma once
#include <windows.h>

void DrawClock(HDC hDC, INT x, INT y, INT width, INT height, HBITMAP hBmpClock, DWORD dwROP, int seconds, int minutes);
BOOL DrawBitmap(HDC hDC, INT x, INT y, INT width, INT height, HBITMAP hBitmap, DWORD dwROP);
