#include <cmath>

#include "draw.h"

BOOL DrawEllipse(HDC hDC, RECT ellipseRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Ellipse(hDC, ellipseRect.left + 10, ellipseRect.top + 10, ellipseRect.right - 10, ellipseRect.bottom - 50);
	DrawText(hDC, "Ellipse", -1, &ellipseRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}

BOOL DrawRectangle(HDC hDC, RECT rectangleRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Rectangle(hDC, rectangleRect.left + 10, rectangleRect.top + 10, rectangleRect.right - 10, rectangleRect.bottom - 50);
	DrawText(hDC, "Rectangle", -1, &rectangleRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}

BOOL DrawSector(HDC hDC, RECT sectorRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Pie(hDC, sectorRect.left + 10, sectorRect.top + 10, sectorRect.right - 10, sectorRect.bottom - 50,
		sectorRect.right - 10,
		sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2,
		sectorRect.left + (sectorRect.right - sectorRect.left) / 2 + (sectorRect.right - sectorRect.left - 20)*sqrt(3) / 4,
		sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2 - (sectorRect.right - sectorRect.left - 20) / 4);
	DrawText(hDC, "Sector", -1, &sectorRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}

BOOL DrawRhombus(HDC hDC, RECT rhombusRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	POINT rhombusPoints[4];
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	rhombusPoints[0] = { rhombusRect.left + 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
	rhombusPoints[1] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.top + 10 };
	rhombusPoints[2] = { rhombusRect.right - 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
	rhombusPoints[3] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.bottom - 50 };
	result = Polygon(hDC, rhombusPoints, 4);
	DrawText(hDC, "Rhombus", -1, &rhombusRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}