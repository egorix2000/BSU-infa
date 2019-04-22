#pragma once
#include <windows.h>
#include <vector>
#include "Ball.h"

void drawRect(HDC& hdc, RECT rect, COLORREF color);
void drawBallsWithRopes(HDC& hdc, std::vector<Ball> balls, POINT suspension);