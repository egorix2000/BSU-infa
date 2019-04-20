#ifndef FigureI_h
#define FigureI_h

#include "Figure.h"

class FigureI : public Figure {
public:
    FigureI(int color);
};

FigureI::FigureI(int color) {
    n_ = 4;
    color_ = color;
    tiles_ = new Tile[4];
    tiles_[0].x = 1;
    tiles_[1].x = 1;
    tiles_[2].x = 1;
    tiles_[3].x = 1;
    tiles_[0].y = 0;
    tiles_[1].y = 1;
    tiles_[2].y = 2;
    tiles_[3].y = 3;
}

#endif /* FigureI_h */
