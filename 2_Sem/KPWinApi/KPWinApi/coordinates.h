#pragma once
#include <windows.h>
#include <cmath> 

POINT polarToDecart(double angle, double radius);
int calcSquaredDistance(POINT p1, POINT p2);