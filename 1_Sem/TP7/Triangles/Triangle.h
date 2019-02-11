#pragma once
#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Point.h"

class Triangle{
    private:
        Point v1_;
        Point v2_;
        Point v3_;
    public:
        Triangle();
        Triangle(const Point& v1, const Point& v2, const Point& v3);
        Triangle(Triangle& triangle);
        Point getV1();
        Point getV2();
        Point getV3();
        void setV1(const Point& v1);
        void setV2(const Point& v2);
        void setV3(const Point& v3);
        Triangle* move(const double x, const double y);
        double calculateSquare();
        bool doesContainsPoint(Point& point);
        bool isInside(Triangle& triangle); // return true if 'this' inside triangle
};

#endif // TRIANGLE_H_INCLUDED
