#include <iostream>

#include "CharVectorManager.h"
#include "Vector/VectorIterator.h"

void CharVectorManager::print(VectorIterator<char>& iterator) {
    while (!(++iterator)) {
        std::cout << *iterator;
    }
    std::cout << std::endl;
}

void CharVectorManager::printReverse(VectorIterator<char>& iterator) {
    while (!(--iterator)) {
        std::cout << *iterator;
    }
    std::cout << std::endl;
}