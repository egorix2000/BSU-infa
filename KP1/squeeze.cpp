/**
Вариант 1
Дана матрица размера m x n. "Уплотнить" ее, удаляя из нее строки и столбцы, заполненные нулями.
Быченок Егор

tests in folder "tests"
**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/squeeze/input1.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/squeeze/output1.txt";


int printTwoDimensionalArray(int **a, int n, int m, ofstream& fout){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            fout << a[t][i] << " ";
        }
        fout << endl;
    }
    return 0;
}

int** deleteRow(int** a, int& n, int& m, int iRow){
    int** newA = new int*[n-1];
    for (int i = 0; i < n-1; i++){
        newA[i] = new int[m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i < iRow){
                newA[i][j] = a[i][j];
            } else if(i > iRow) {
                newA[i-1][j] = a[i][j];
            }
        }
    }
    n--;
    return newA;
}

int** deleteColumn(int** a, int& n, int& m, int iColumn){
    int** newA = new int*[n];
    for (int i = 0; i < n; i++){
        newA[i] = new int[m-1];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j < iColumn){
                newA[i][j] = a[i][j];
            } else if(j > iColumn) {
                newA[i][j-1] = a[i][j];
            }
        }
    }
    m--;
    return newA;
}

int enterTwoDimensionalArrayFromFile(int** a, int n, int m, ifstream& fin){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            fin >> a[t][i];
        }
    }
    return 0;
}

int** removeAllZeroRows(int** a, int &n, int &m){
    bool isZeroRow;
    for (int t = 0; t < n; t++){
        isZeroRow = true;
        for (int i = 0; i < m; i++){
            if (a[t][i] != 0){
                isZeroRow = false;
                break;
            }
        }
        if (isZeroRow){
            a = deleteRow(a, n, m, t);
            t--;
        }
    }

    return a;
}

int** removeAllZeroColumns(int** a, int &n, int &m){
    bool isZeroColumn;
    for (int t = 0; t < m; t++){
        isZeroColumn = true;
        for (int i = 0; i < n; i++){
            if (a[i][t] != 0){
                isZeroColumn = false;
                break;
            }
        }
        if (isZeroColumn){
            a = deleteColumn(a, n, m, t);
            t--;
        }
    }
    return a;
}

int main(){
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    int n;
    int m;
    int** a;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        fin >> n >> m;

        a = new int*[n];
        for (int i = 0; i < n; i++){
            a[i] = new int[m];
        }

        enterTwoDimensionalArrayFromFile(a, n, m, fin);

        a = removeAllZeroRows(a, n, m);
        a = removeAllZeroColumns(a, n, m);
        printTwoDimensionalArray(a, n, m, fout);
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
