/**

Дан массив целых чисел. Реализовать функцию для обработки массива целых чисел.
Функция находит минимальный элемент массива и сортирует все элементы левее
его по убыванию, а правее его – по возрастанию.
Функция возвращает индекс минимального элемента.


input			            output
-----------------------------------
7                           5 3 1 3 4 6 10
3 5 1 4 3 6 10              2

1                           1
1                           0

5                           1 2 3 5 7
1 5 3 7 2                   0

5                           8 5 4 2 1
4 2 8 5 1                   4

**/


#include <iostream>
#include "MyLib.h"

using namespace std;

bool comparator1(int a, int b){
    if (a < b){
        return true;
    } else {
        return false;
    }
}

int specialSort(int *a, int n){
    int minIndex = 0;
    for (int t = 1; t < n; t++){
        if (a[t] < a[minIndex]){
            minIndex = t;
        }
    }
    sortArray(a, minIndex, comparator1);
    sortArray(a+minIndex+1, n-minIndex-1);
    return minIndex;
}

int main()
{
    int n;
    int minIndex;
    int *a;
    cout << "Enter array length" << endl;
    cin >> n;

    a = new int[n];
    cout << "Enter array elements" << endl;
    enterArray(a, n);

    minIndex = specialSort(a, n);

    cout << "Sorted array: ";
    coutArray(a, n);
    cout << "Min index: " << minIndex << endl;
    return 0;
}
