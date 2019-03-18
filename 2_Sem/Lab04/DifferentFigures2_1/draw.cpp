#include <cmath>

#include "draw.h"
#include "style.h"

BOOL DrawEllipse(HDC hDC, RECT ellipseRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Ellipse(hDC, ellipseRect.left + MARGIN_TEN_PX, ellipseRect.top + MARGIN_TEN_PX, 
		ellipseRect.right - MARGIN_TEN_PX, ellipseRect.bottom - MARGIN_FIFTY_PX);
	DrawText(hDC, "Ellipse", -1, &ellipseRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}

BOOL DrawRectangle(HDC hDC, RECT rectangleRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Rectangle(hDC, rectangleRect.left + MARGIN_TEN_PX, rectangleRect.top + MARGIN_TEN_PX, 
		rectangleRect.right - MARGIN_TEN_PX, rectangleRect.bottom - MARGIN_FIFTY_PX);
	DrawText(hDC, "Rectangle", -1, &rectangleRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}

BOOL DrawSector(HDC hDC, RECT sectorRect, int style, int penWidth, COLORREF penColor, COLORREF brushColor) {
	BOOL result;
	SelectObject(hDC, CreatePen(style, penWidth, penColor));
	SelectObject(hDC, CreateSolidBrush(brushColor));
	result = Pie(hDC, sectorRect.left + MARGIN_TEN_PX, sectorRect.top + MARGIN_TEN_PX, 
		sectorRect.right - MARGIN_TEN_PX, sectorRect.bottom - MARGIN_FIFTY_PX,
		sectorRect.right - MARGIN_TEN_PX,
		sectorRect.top + (sectorRect.bottom - sectorRect.top - MARGIN_FOURTY_PX) / 2,
		sectorRect.left + (sectorRect.right - sectorRect.left) / 2 + (sectorRect.right - sectorRect.left - MARGIN_TWENTY_PX)*sqrt(3) / 4,
		sectorRect.top + (sectorRect.bottom - sectorRect.top - MARGIN_FOURTY_PX) / 2 - (sectorRect.right - sectorRect.left - MARGIN_TWENTY_PX) / 4);
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
	rhombusPoints[0] = { rhombusRect.left + MARGIN_TEN_PX, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - MARGIN_FOURTY_PX) / 2 };
	rhombusPoints[1] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.top + MARGIN_TEN_PX };
	rhombusPoints[2] = { rhombusRect.right - MARGIN_TEN_PX, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - MARGIN_FOURTY_PX) / 2 };
	rhombusPoints[3] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.bottom - MARGIN_FIFTY_PX };
	result = Polygon(hDC, rhombusPoints, 4);
	DrawText(hDC, "Rhombus", -1, &rhombusRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
	return result;
}