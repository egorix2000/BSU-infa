#include "coordinates.h"

POINT polarToDecart(double angle, double radius) {
	return POINT{ (long)(radius * cos(angle)), (long)(radius * sin(angle)) };
}

int calcSquaredDistance(POINT p1, POINT p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}