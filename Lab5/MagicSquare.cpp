/**
Дана квадратная матрица n-го порядка, состоящая из целых чисел. Определить является ли она магическим квадратом

input			            output
-----------------------------------------
3
4 9 2
3 5 7
8 1 6                       Magic square

4
16 3 2 13
5 10 11 8
9 6 7 12
4 15 14 1                   Magic square

3
0 0 0
0 0 0
0 0 0                       Magic square

3
4 9 2
3 5 7
8 1 5                       Not magic square

**/


#include <iostream>
#include "TwoDimensionalArrayLib.h"

using namespace std;


int main()
{
    int n;
    bool isMagic = true;
    int sum = 0;
    int **matrix;

    cout << "Enter n" << endl;
    cin >> n;

    matrix = new int*[n];
    for (int t = 0; t < n; t++){
        matrix[t] = new int [n];
    }

    cout << "Enter matrix" << endl;
    enterTwoDimensionalArray(matrix, n);

    sum = sumInRow(matrix, n, 0);

    for (int t = 0; t < n; t++){
        if (sum != sumInRow(matrix, n, t) ||
                sum != sumInColumn(matrix, n, t) ||
                    sum != sumInFirstDiagonal(matrix, n) ||
                        sum != sumInSecondDiagonal(matrix, n)) {
            isMagic = false;
            break;
        }
    }

    if (isMagic){
        cout << "Magic square" << endl;
    } else {
        cout << "Not magic square" << endl;
    }
    return 0;
}
