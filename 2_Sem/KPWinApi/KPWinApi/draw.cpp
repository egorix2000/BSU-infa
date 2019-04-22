#include "draw.h"
#include "coordinates.h"

void drawRect(HDC& hdc, RECT rect, COLORREF color) {
	SelectObject(hdc, CreateSolidBrush(color));

	Rectangle(hdc, rect.left, rect.top,
		rect.right, rect.bottom);

	DeleteObject(SelectObject(hdc, GetStockObject(BLACK_BRUSH)));
}

void drawBallsWithRopes(HDC& hdc, std::vector<Ball> balls, POINT suspension) {
	POINT decartCenter;
	POINT decartPoint;
	for (std::vector<Ball>::iterator it = balls.begin(); it != balls.end(); it++) {
		SelectObject(hdc, CreateSolidBrush((*it).color));

		decartCenter = polarToDecart((*it).angle, (*it).radius);
		Ellipse(hdc, decartCenter.x - (*it).ballRadius + suspension.x, - decartCenter.y - (*it).ballRadius + suspension.y,
			decartCenter.x + (*it).ballRadius + suspension.x, - decartCenter.y + (*it).ballRadius + suspension.y);

		DeleteObject(SelectObject(hdc, GetStockObject(BLACK_BRUSH)));

		decartPoint = polarToDecart((*it).angle, (*it).radius - (*it).ballRadius);
		MoveToEx(hdc, suspension.x, suspension.y, nullptr);
		LineTo(hdc, decartPoint.x + suspension.x, - decartPoint.y + suspension.y);
	}
}