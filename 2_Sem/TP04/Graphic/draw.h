#pragma once
#include <Windows.h>
#include "coodinateSystemLib.h"
#include "Graph.h"

void drawRect(HDC& hdc, RECT rect);

void drawAxes(HDC& hdc, RECT rect, POINT origin);
void drawFunction(HDC& hdc, RECT rect, Graph graph);
void drawScalesOfAxes(HDC& hdc, RECT rect, POINT origin, Graph graphg,
	int amountOfScalesByAxe, int scaleSize, int graphDecimalPrecision);
void drawPointAtGraph(HDC& hdc, RECT rect, POINT origin, POINT mousePosition,
	Graph graph, int graphDecimalPrecision);
