/**
Заполнить квадратную матрицу (n x n) натуральными четными числами 2,4,6,8,... по сходящейся к центру линии ( по спирали).

input			            output
-----------------------------------------

2                           8 6
                            2 4

3                           18 16 14
                            4  2 12
                            6  8 10


5                           50 48 46 44 42
                            20 18 16 14 40
                            22  4  2 12 38
                            24  6  8 10 36
                            26 28 30 32 34



10                          200 198 196 194 192 190 188 186 184 182
                            130 128 126 124 122 120 118 116 114 180
                            132  74  72  70  68  66  64  62 112 178
                            134  76  34  32  30  28  26  60 110 176
                            136  78  36  10   8   6  24  58 108 174
                            138  80  38  12   2   4  22  56 106 172
                            140  82  40  14  16  18  20  54 104 170
                            142  84  42  44  46  48  50  52 102 168
                            144  86  88  90  92  94  96  98 100 166
                            146 148 150 152 154 156 158 160 162 164

**/


#include <iostream>
#include "TwoDimensionalArrayLib.h"

using namespace std;


int fillMatrixByOddNumbers(int **matrix, int n){
    int start = n*n*2;
    int startCopy = start;
    for (int t = 0; t <= n/2; t++){
        for (int i = t; i < n-t; i++){
            matrix[t][i] = start;
            start -= 2;
        }
        for (int i = t+1; i < n-t; i++){
            matrix[i][n-t-1] = start;
            start -= 2;
        }
        for (int i = n-t-2; i >= t; i--){
            matrix[n-t-1][i] = start;
            start -= 2;
        }
        for (int i = n-t-2; i > t; i--){
            matrix[i][t] = start;
            start -= 2;
        }
    }
    return startCopy;
}

int digitsInN(int n){
    int ans = 0;
    while (n > 0){
        n /= 10;
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    int width;
    int start;
    int **matrix;

    cout << "Enter n" << endl;
    cin >> n;

    matrix = new int*[n];
    for (int t = 0; t < n; t++){
        matrix[t] = new int [n];
    }

    start = fillMatrixByOddNumbers(matrix, n);

    width = digitsInN(start)+1;

    printFormattedTwoDimensionalArray(matrix, n, width);
    return 0;
}
