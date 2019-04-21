#include "draw.h"

void drawRect(HDC& hdc, RECT rect) {
	Rectangle(hdc, rect.left, rect.top,
		rect.right, rect.bottom);
}

void drawAxes(HDC& hdc, RECT rect, POINT origin) {
	MoveToEx(hdc, 0, origin.y, NULL);
	LineTo(hdc, rect.right, origin.y);
	MoveToEx(hdc, origin.x, 0, NULL);
	LineTo(hdc, origin.x, rect.bottom);
}

void drawScalesOfAxes(HDC& hdc, RECT rect, POINT origin) {
	double g_valueOfDivision_x = (G_END_X - G_START_X) /
		((double)amountOfScalesByAxe + 1);
	double g_valueOfDivision_y = (G_END_Y - G_START_Y) /
		((double)amountOfScalesByAxe + 1);
	double g_axe_x = G_START_X + g_valueOfDivision_x;
	double g_axe_y = G_START_Y + g_valueOfDivision_y;
	POINT temp;
	std::string text;
	for (int i = 0; i < amountOfScalesByAxe; i++) {
		temp = graphpointToPoint(g_axe_x, g_axe_y, rect);
		MoveToEx(hdc, temp.x, origin.y - scaleSize, NULL);
		LineTo(hdc, temp.x, origin.y + scaleSize);
		fillWithCoordinate(text, g_axe_x);
		TextOut(hdc, temp.x - scaleSize, origin.y + 2 * scaleSize,
			_T(text.c_str()), text.size());
		g_axe_x += g_valueOfDivision_x;
		MoveToEx(hdc, origin.x - scaleSize, temp.y, NULL);
		LineTo(hdc, origin.x + scaleSize, temp.y);
		fillWithCoordinate(text, g_axe_y);
		TextOut(hdc, origin.x + 2 * scaleSize, temp.y - scaleSize,
			_T(text.c_str()), text.size());
		g_axe_y += g_valueOfDivision_y;
	}
}

void drawPointerToAxes(HDC & hdc, RECT rect, POINT origin) {
	HPEN pen = CreatePen(PS_SOLID, 1, pointerToAxesColor);
	SelectObject(hdc, pen);
	MoveToEx(hdc, mousePosition.x, origin.y, NULL);
	LineTo(hdc, mousePosition.x, mousePosition.y);
	MoveToEx(hdc, origin.x, mousePosition.y, NULL);
	LineTo(hdc, mousePosition.x, mousePosition.y);
	DeleteObject(pen);
}

void drawGraphic(HDC & hdc, RECT rect) {
	for (int x = 1; x < rect.right; x++) {
		GraphPoint graphpoint = pointToGraphpoint(x, 0, rect);
		POINT point = graphpointToPoint(0, func(graphpoint.g_x), rect);
		SetPixel(hdc, x, point.y, functionColor);
	}
}

void drawPointAtGraph(HDC & hdc, RECT rect, POINT origin) {
	GraphPoint graphpoint = pointToGraphpoint(mousePosition.x,
		mousePosition.y,
		rect);
	graphpoint.g_y = func(graphpoint.g_x);
	POINT windowPoint = graphpointToPoint(graphpoint.g_x,
		graphpoint.g_y,
		rect);
	HPEN pen = CreatePen(PS_SOLID, 5, pointColor);
	SelectObject(hdc, pen);
	Rectangle(hdc, windowPoint.x - 2, windowPoint.y - 2,
		windowPoint.x + 2, windowPoint.y + 2);
	std::string coor1, coor2;
	fillWithCoordinate(coor1, graphpoint.g_x);
	fillWithCoordinate(coor2, graphpoint.g_y);
	std::string result = "(" + coor1 + ", " + coor2 + ")";
	SetTextColor(hdc, pointColor);
	TextOut(hdc, windowPoint.x + 2, windowPoint.y + 2,
		_T(result.c_str()), result.size());
	DeleteObject(pen);
}
