#pragma once
#ifndef COMPARATOR_H_INCLUDED
#define COMPARATOR_H_INCLUDED

#include <string>
#include "Train.h"

class Comparator {
    public:
        static bool compareTrainsByTime(Train& train1, Train& train2);
        static bool compareTrainsByDestination(Train& train1, Train& train2);
};

#endif // COMPARATOR_H_INCLUDED
