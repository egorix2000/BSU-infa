#include "draw.h"

void drawRect(HDC& hdc, RECT rect) {
	Rectangle(hdc, rect.left, rect.top,
		rect.right, rect.bottom);
}

void drawBallsWithRopes(HDC& hdc, std::vector<Ball> balls, POINT suspension) {
	for (std::vector<Ball>::iterator it = balls.begin(); it != balls.end(); it++) {
		SelectObject(hdc, CreateSolidBrush((*it).color));
		Ellipse(hdc, (*it).center.x - (*it).radius, (*it).center.y - (*it).radius,
			(*it).center.x + (*it).radius, (*it).center.y + (*it).radius);
		DeleteObject(SelectObject(hdc, GetStockObject(BLACK_BRUSH)));
		MoveToEx(hdc, suspension.x, suspension.y, nullptr);
		LineTo(hdc, (*it).center.x, (*it).center.y);
	}
}