#include "draw.h"

void DrawTrafficLight(HDC hDC, RECT trafficLightRect, const TrafficLight & trafficLight, Circle circles[3]) {
	SelectObject(hDC, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));

	SelectObject(hDC, CreateSolidBrush(RGB(100, 80, 100)));
	Rectangle(hDC, trafficLightRect.left, trafficLightRect.top, trafficLightRect.right, trafficLightRect.bottom);
	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));


	for (int i = 0; i < 3; i++) {
		if (trafficLight[i].getType() == trafficLight.getCurrentLight().getType() &&
				trafficLight.getIsMainColor()) {
			SelectObject(hDC, CreateSolidBrush(trafficLight[i].getMainColor()));
		} else {
			SelectObject(hDC, CreateSolidBrush(trafficLight[i].getDarkColor()));
		}
		if (trafficLight[i].getIsFlickerSize() && circles[i].isBig) {
			circles[i].xLeft = trafficLightRect.left + 10;
			circles[i].yTop = trafficLightRect.top + i * trafficLightRect.bottom / 3 + 10;
			circles[i].xRight = trafficLightRect.right - 10;
			circles[i].yBottom = trafficLightRect.top + (i + 1) * (trafficLightRect.bottom / 3 - 10);
			Ellipse(hDC, circles[i].xLeft, circles[i].yTop, circles[i].xRight, circles[i].yBottom);
		} else {
			circles[i].xLeft = trafficLightRect.left + 5;
			circles[i].yTop = trafficLightRect.top + i * trafficLightRect.bottom / 3 + 5;
			circles[i].xRight = trafficLightRect.right - 5;
			circles[i].yBottom = trafficLightRect.top + (i + 1) * (trafficLightRect.bottom / 3 - 5);
			Ellipse(hDC, circles[i].xLeft, circles[i].yTop, circles[i].xRight, circles[i].yBottom);
		}
		circles[i].type = trafficLight[i].getType();
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
	}

	DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
}
