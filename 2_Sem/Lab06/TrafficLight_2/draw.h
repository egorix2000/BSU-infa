#pragma once
#include <windows.h>
#include "TrafficLight.h"
#include "Circle.h"

void DrawTrafficLight(HDC hDC, RECT trafficLightRect, const TrafficLight &trafficLight, Circle circles[3]);
