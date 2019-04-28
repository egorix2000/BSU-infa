#include "draw.h"

const COLORREF functionColor = RGB(255, 0, 0);
const COLORREF pointerToAxesColor = RGB(0, 255, 0);
const COLORREF pointColor = RGB(0, 0, 255);

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

void drawScalesOfAxes(HDC& hdc, RECT rect, POINT origin, Graph graph,
						int amountOfScalesByAxe, int scaleSize, int graphDecimalPrecision) {
	double g_valueOfDivision_x = (graph.getRightBorder() - graph.getLeftBorder()) /
		((double)amountOfScalesByAxe + 1);
	double g_valueOfDivision_y = (graph.getBottomBorder() - graph.getTopBorder()) /
		((double)amountOfScalesByAxe + 1);
	double g_axe_x = graph.getLeftBorder() + g_valueOfDivision_x;
	double g_axe_y = graph.getTopBorder() + g_valueOfDivision_y;
	POINT temp;
	std::string text;
	for (int i = 0; i < amountOfScalesByAxe; i++) {
		temp = graphPointToPoint(g_axe_x, g_axe_y, rect, graph);
		MoveToEx(hdc, temp.x, origin.y - scaleSize, NULL);
		LineTo(hdc, temp.x, origin.y + scaleSize);
		doubleToStringWithPrecision(text, g_axe_x, graphDecimalPrecision);
		TextOut(hdc, temp.x - scaleSize, origin.y + 2 * scaleSize,
			_T(text.c_str()), text.size());
		g_axe_x += g_valueOfDivision_x;
		MoveToEx(hdc, origin.x - scaleSize, temp.y, NULL);
		LineTo(hdc, origin.x + scaleSize, temp.y);
		doubleToStringWithPrecision(text, g_axe_y, graphDecimalPrecision);
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, origin.x + 2 * scaleSize, temp.y - scaleSize,
			_T(text.c_str()), text.size());
		g_axe_y += g_valueOfDivision_y;
	}
}

void drawFunction(HDC & hdc, RECT rect, Graph graph) {
	for (int x = 1; x < rect.right; x++) {
		DoublePoint graphpoint = pointToGraphPoint(x, 0, rect, graph);
		POINT point = graphPointToPoint(0, graph.getValue(graphpoint.x), rect, graph);
		SetPixel(hdc, x, point.y, functionColor);
	}
}

void drawPointAtGraph(HDC & hdc, RECT rect, POINT origin, POINT mousePosition, 
	Graph graph, int graphDecimalPrecision) {
	DoublePoint graphpoint = pointToGraphPoint(mousePosition.x,
		mousePosition.y,
		rect, graph);
	graphpoint.y = graph.getValue(graphpoint.x);
	POINT windowPoint = graphPointToPoint(graphpoint.x,
		graphpoint.y,
		rect, graph);
	HPEN pen = CreatePen(PS_SOLID, 5, pointColor);
	SelectObject(hdc, pen);
	Ellipse(hdc, windowPoint.x - 2, windowPoint.y - 2,
		windowPoint.x + 2, windowPoint.y + 2);
	std::string coor1, coor2;
	doubleToStringWithPrecision(coor1, graphpoint.x, graphDecimalPrecision);
	doubleToStringWithPrecision(coor2, graphpoint.y, graphDecimalPrecision);
	std::string result = "(" + coor1 + ", " + coor2 + ")";
	SetTextColor(hdc, pointColor);
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, windowPoint.x - 10, windowPoint.y - 20,
		_T(result.c_str()), result.size());
	DeleteObject(pen);
}
