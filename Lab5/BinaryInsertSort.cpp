/**
Написать функцию, которая производит двоичный поиск места размещения нового элемента
в упорядоченном массиве и возвращает указатель на место включения нового элемента.
С помощью данной функции реализовать сортировку вставками.

input			            output
-----------------------------------------

1                           1
1

2                           1 2
1 2

2                           1 2
2 1

5                           1 2 3 4 5
4 1 3 2 5

10
0 0 0 0 0 1 0 0 0 0         0 0 0 0 0 0 0 0 0 1

8
5 3 8 3 1 6 6 3             1 3 3 3 5 6 6 8

**/


#include <iostream>
#include "OneDimensionalArrayLib.h"

using namespace std;


int main()
{
    int n;
    int *a;

    cout << "Enter length of array" << endl;
    cin >> n;

    a = new int[n];

    cout << "Enter array" << endl;
    enterArray(a, n);

    //fillArrayRandom(a, n);
    //printArray(a, n);

    insertSortArrayWithBinarySearch(a, n);
    printArray(a, n);
    return 0;
}
