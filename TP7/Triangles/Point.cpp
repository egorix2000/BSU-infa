#include "Point.h"

Point::Point(){
    x_ = 0;
    y_ = 0;
}

Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}

double Point::getX(){
    return x_;
}

void Point::setX(double x){
    x_ = x;
}

double Point::getY(){
    return y_;
}

void Point::setY(double y){
    y_ = y;
}

int Point::classify(Point& vectorBegin, Point& vectorEnd){
    double a11 = vectorEnd.getX() - vectorBegin.getX();
    double a21 = x_ - vectorBegin.getX();
    double a12 = vectorEnd.getY() - vectorBegin.getY();
    double a22 = y_ - vectorBegin.getY();
    double determinant = a11 * a22 - a21 * a12;

    if (determinant > 0){
        return LEFT;
    }
    else if (determinant < 0){
        return RIGHT;
    } else {
        if ((a11 * a21 < 0) || (a12 * a22 < 0)){
            return BEHIND;
        }
        else if (a11 * a11 + a12 * a12 < a21 * a21 + a22 * a22){
            return AHEAD;
        }
        return BETWEEN;
    }
}
