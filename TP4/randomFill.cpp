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
#include <cctype>
#include <cstring>
#include "TwoDimensionalArrayLib.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

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

    //change file paths to yours
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    int nTests;
    int n, m;
    int** a;

    fin.open("Downloads/A/tests/randomFill/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/randomFill/output.txt");
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
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
