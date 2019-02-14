#include <iostream>
#include <string>
#include <cmath>

#include "Vector/Vector.h"
#include "Vector/VectorException.h"
#include "CharVectorManager.h"

using namespace std;

int main()
{
    string letters = "abcdefghijklmnopqrstuvwxyz";
    Vector<char> alphabet;
    for (int i = 0; i < letters.length(); i++){
        alphabet.push_back(letters[i]);
    }
    VectorIterator<char> iterator(alphabet);
    iterator.moveToBegin();
    CharVectorManager::print(iterator);
    iterator.moveToEnd();
    CharVectorManager::printReverse(iterator);
    return 0;
}