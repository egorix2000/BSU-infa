/**
Используя датчик случайных чисел, заполнись двумерный массив (n x m) неповторяющимися числами.

input:
numberOfTests
tests

**/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"

using namespace std;

//change file paths to yours
ifstream fin("Downloads/A/tests/randomFill/input.txt");
ofstream fout("Downloads/A/tests/randomFill/output.txt");

bool hasElement(int** a, int m, int row, int column, int element){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == element){
                return true;
            }
        }
    }
    for (int j = 0; j < column; j++){
            if (a[row][j] == element){
                return true;
            }
    }
    return false;
}

int fillRandomWithoutEqual(int** a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = rand()%1000;
            while(hasElement(a, m, i, j, a[i][j])){
                a[i][j] = rand()%1000;
            }
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int nTests;
    int n, m;
    int** a;
    fin >> nTests;

    for (int i = 0; i < nTests; i++){
        fin >> n >> m;
        a = new int*[n];
        for (int i = 0; i < n; i++){
            a[i] = new int[m];
        }
        fillRandomWithoutEqual(a, n, m);
        printFormattedTwoDimensionalArrayToFile(a, n, m, 4, fout);
        fout << endl;
    }
    return 0;
}
