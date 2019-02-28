#ifndef FigureL_h
#define FigureL_h

#include "Figure.h"

class FigureL : public Figure {
public:
    FigureL(int color);
};

FigureL::FigureL(int color) {
    n_ = 4;
    color_ = color;
    tiles_ = new Tile[4];
    tiles_[0].x = 0;
    tiles_[1].x = 1;
    tiles_[2].x = 1;
    tiles_[3].x = 1;
    tiles_[0].y = 0;
    tiles_[1].y = 0;
    tiles_[2].y = 1;
    tiles_[3].y = 2;
};

#endif /* FigureL_h */
