#ifndef FigureO_h
#define FigureO_h

#include "Figure.h"

class FigureO : public Figure {
public:
    FigureO(int color);
};

FigureO::FigureO(int color) {
    n_ = 4;
    color_ = color;
    tiles_ = new Tile[4];
    tiles_[0].x = 0;
    tiles_[1].x = 1;
    tiles_[2].x = 0;
    tiles_[3].x = 1;
    tiles_[0].y = 0;
    tiles_[1].y = 0;
    tiles_[2].y = 1;
    tiles_[3].y = 1;
}

#endif /* FigureO_h */
