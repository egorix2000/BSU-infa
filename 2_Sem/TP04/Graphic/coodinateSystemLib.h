#pragma once
#include <windows.h>
#include <tchar.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>
#include <windowsx.h>
#include <functional>
#include "Graph.h"

struct DoublePoint {
	double x;
	double y;
};

void resizeAxes(RECT rect, RECT selection, Graph& graph);
void normalizeRect(RECT& rect);
POINT getOriginAtWindow(RECT rect, Graph& graph, int scaleSize);
DoublePoint pointToGraphPoint(int x, int y, RECT rect, Graph& graph);
POINT graphPointToPoint(double x, double y, RECT rect, Graph& graph);
void doubleToStringWithPrecision(std::string& s, double doubleNumber, int precision);