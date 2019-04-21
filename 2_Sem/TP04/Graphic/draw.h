#pragma once
#include <windows.h>

void drawRect(HDC& hdc, RECT rect);

void drawAxes(HDC& hdc, RECT rect, POINT origin);
void drawGraphic(HDC& hdc, RECT rect);
void drawPointerToAxes(HDC& hdc, RECT rect, POINT origin);
void drawScalesOfAxes(HDC& hdc, RECT rect, POINT origin);
void drawPointAtGraph(HDC& hdc, RECT rect, POINT origin);