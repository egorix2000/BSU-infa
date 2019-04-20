#ifndef FigureFactory_h
#define FigureFactory_h

#include "Figure.h"
#include "FigureL.h"
#include "FigureI.h"
#include "FigureO.h"
#include "FigureZ.h"
#include "FigureS.h"
#include "FigureT.h"
#include "FigureJ.h"

class FigureFactory {
public:
    static Figure* createRandomSizeFourFigure();
};

Figure* FigureFactory::createRandomSizeFourFigure() {
    int colorNum = 1 + rand() % 7;
    int k = rand() % 7;
    switch (k) {
        case 0:
            return new FigureI(colorNum);
            break;
        case 1:
            return new FigureL(colorNum);
            break;
        case 2:
            return new FigureO(colorNum);
            break;
        case 3:
            return new FigureZ(colorNum);
            break;
        case 4:
            return new FigureS(colorNum);
            break;
        case 5:
            return new FigureT(colorNum);
            break;
        case 6:
            return new FigureJ(colorNum);
            break;
        default:
            break;
    }
}

#endif /* FigureFactory_h */
