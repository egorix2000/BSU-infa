#pragma once
#undef __STRICT_ANSI__
#define _USE_MATH_DEFINES
#include "diagram.h"
#include "task2.h"
#include <windows.h>
#include <iomanip>
#include <tchar.h>
#include <algorithm>
#include <sstream>
#include <cmath>
class PieChart : public Diagram
{
    public:
        PieChart();
        void draw(HDC &hdc, RECT drawingArea);
    private:
        RECT getPieDrawingArea(HDC &hdc, RECT drawingArea);
};