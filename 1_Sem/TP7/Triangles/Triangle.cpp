#include "Triangle.h"
#include "Point.h"

Triangle::Triangle(){
    v1_ = *(new Point(0, 0));
    v2_ = *(new Point(0, 0));
    v3_ = *(new Point(0, 0));
}

Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3){
    v1_ = v1;
    v2_ = v2;
    v3_ = v3;
}

Triangle::Triangle(Triangle& triangle){
    v1_ = triangle.getV1();
    v2_ = triangle.getV2();
    v3_ = triangle.getV3();
}

Point Triangle::getV1(){
    return v1_;
}

Point Triangle::getV2(){
    return v2_;
}

Point Triangle::getV3(){
    return v3_;
}

void Triangle::setV1(const Point& v1){
    v1_ = v1;
}

void Triangle::setV2(const Point& v2){
    v2_ = v2;
}

void Triangle::setV3(const Point& v3){
    v3_ = v3;
}

Triangle* Triangle::move(const double x, const double y){
    v1_.setX(v1_.getX() + x);
    v1_.setY(v1_.getY() + y);
    v2_.setX(v2_.getX() + x);
    v2_.setY(v2_.getY() + y);
    v3_.setX(v3_.getX() + x);
    v3_.setY(v3_.getY() + y);
    return this;
}

double Triangle::calculateSquare(){
    double a11 = v1_.getX() - v3_.getX();
    double a21 = v2_.getX() - v3_.getX();
    double a12 = v1_.getY() - v3_.getY();
    double a22 = v2_.getY() - v3_.getY();
    double determinant = a11 * a22 - a21 * a12;
    if (determinant < 0){
        determinant *= -1;
    }
    return determinant / 2;
}



bool Triangle::doesContainsPoint(Point& point) {
    int or1 = point.classify(v1_, v2_);
    int or2 = point.classify(v2_, v3_);
    int or3 = point.classify(v3_, v1_);

    if (
        ((or1 == RIGHT || or1 == BETWEEN)
            && (or2 == RIGHT || or2 == BETWEEN)
            && (or3 == RIGHT || or3 == BETWEEN)) ||
        ((or1 == LEFT || or1 == BETWEEN)
            && (or2 == LEFT || or2 == BETWEEN)
            && (or3 == LEFT || or3 == BETWEEN))
        ){
        return true;
    }
    else {
        return false;
    }
}

bool Triangle::isInside(Triangle& triangle){
    if (triangle.doesContainsPoint(v1_)
            && triangle.doesContainsPoint(v2_)
            && triangle.doesContainsPoint(v3_)){
        return true;
    } else {
        return false;
    }
}
