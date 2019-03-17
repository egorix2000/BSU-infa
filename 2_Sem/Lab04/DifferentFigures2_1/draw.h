#pragma once
#include <windows.h>

BOOL DrawEllipse(HDC hDC, RECT ellipseRect, int style, int width, COLORREF penColor, COLORREF brushColor);
BOOL DrawRectangle(HDC hDC, RECT rectangleRect, int style, int width, COLORREF penColor, COLORREF brushColor);
BOOL DrawSector(HDC hDC, RECT sectorRect, int style, int width, COLORREF penColor, COLORREF brushColor);
BOOL DrawRhombus(HDC hDC, RECT rhombusRect, int style, int width, COLORREF penColor, COLORREF brushColor);