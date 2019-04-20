#ifndef FigureZ_h
#define FigureZ_h

#include "Figure.h"

class FigureZ : public Figure {
public:
    FigureZ(int color);
};

FigureZ::FigureZ(int color) {
    n_ = 4;
    color_ = color;
    tiles_ = new Tile[4];
    tiles_[0].x = 0;
    tiles_[1].x = 0;
    tiles_[2].x = 1;
    tiles_[3].x = 1;
    tiles_[0].y = 0;
    tiles_[1].y = 1;
    tiles_[2].y = 1;
    tiles_[3].y = 2;
}

#endif /* FigureZ_h */
