#pragma once
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };

class Point{
    private:
        double x_;
        double y_;

    public:
        Point();
        Point(double x, double y);
        double getX();
        void setX(double x);
        double getY();
        void setY(double y);
        /* classify returns:
            1 if lies on the right of the vector,
            -1 if lies on the left of the vector,
            0 if lies on vector,
            2 if lies on continuation of vector*/
        int classify(Point& vectorBegin, Point& vectorEnd);
        //bool isInsideTriangle(Triangle& triangle);
};

#endif // POINT_H_INCLUDED
