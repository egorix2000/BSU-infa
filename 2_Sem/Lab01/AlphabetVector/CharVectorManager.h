#ifndef LAB_CHARVECTORMANAGER_H
#define LAB_CHARVECTORMANAGER_H

#include "Vector/VectorIterator.h"

class CharVectorManager {
public:
    static void print(VectorIterator<char>& iterator);
    static void printReverse(VectorIterator<char>& iterator);
};


#endif //LAB_CHARVECTORMANAGER_H
