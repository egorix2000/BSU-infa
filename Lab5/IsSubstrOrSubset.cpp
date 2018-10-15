/**
Написать программу, которая содержит функцию, принимающую в качестве аргумента,
указатели на два массива (А и В) и размеры массивов. Функция проверяет,
является ли массив В подмножеством/построкой (2 способами, см. зам.)
массива А и возвращает индекс начала найденного фрагмента,
если элемента нет, возвращает -1.

input			            output
-----------------------------------------

7                           Array B is a subset of array A
1 2 5 7 3 2 1               Array B is a substring of array A. Start index: 3
3
7 3 2

8                           Array B is a subset of array A
1 5 2 3 4 8 7 1             Array B is a substring of array A. Start index: 4
4
4 8 7 1

6                           Array B is a subset of array A
1 1 1 1 1 1                 Array B is a substring of array A. Start index: 0
3
1 1 1

7                           Array B is a subset of array A
1 1 1 2 5 4 2               Array B isn't a substring of array A
3
4 1 2

6                           Array B isn't a subset of array A
1 6 4 2 2 1                 Array B isn't a substring of array A
2
1 7


5                           Array B isn't a subset of array A
1 5 2 3 4                   Array B isn't a substring of array A
6
1 5 2 3 4 6

4                           Array B isn't a subset of array A
1 2 3 4                     Array B isn't a substring of array A
4
1 1 1 1
**/


#include <iostream>
#include "OneDimensionalArrayLib.h"

using namespace std;

bool isSubset(int *a, int n, int *b, int m){
    bool *used = new bool[n];
    for (int i = 0; i < n; i++){
        used[i] = false;
    }
    if (m > n){
        return false;
    }
    bool currentElement;
    for (int t = 0; t < m; t++){
        currentElement = false;
        for (int i = 0; i < n; i++){
            if (b[t] == a[i] && !used[i]){
                used[i] = true;
                currentElement = true;
            }
        }
        if (!currentElement){
            return false;
        }
    }
    return true;
}

int isSubstr(int *a, int n, int *b, int m){
    if (m > n){
        return -1;
    }
    bool isSubstr;
    for (int t = 0; t <= n-m; t++){
        isSubstr = true;
        for (int i = 0; i < m; i++){
            if (a[t+i] != b[i]){
                isSubstr = false;
                break;
            }
        }
        if (isSubstr){
            return t;
        }
    }
    return -1;
}

int main()
{
    int n;
    int m;
    int subStr;

    int *a;
    int *b;

    cout << "Enter lenth of array A" << endl;
    cin >> n;

    a = new int[n];

    cout << "Enter array A" << endl;
    enterArray(a, n);

    cout << "Enter lenth of array B" << endl;
    cin >> m;

    b = new int[m];

    cout << "Enter array B" << endl;
    enterArray(b, m);

    if (isSubset(a, n, b, m)){
        cout << "Array B is a subset of array A" << endl;
    } else {
        cout << "Array B isn't a subset of array A" << endl;
    }

    subStr = isSubstr(a, n, b, m);

    if (subStr != -1){
        cout << "Array B is a substring of array A. Start index: " << subStr << endl;
    } else {
        cout << "Array B isn't a substring of array A" << endl;
    }
    return 0;
}
