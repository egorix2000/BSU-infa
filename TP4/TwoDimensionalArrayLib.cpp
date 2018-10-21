#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

void enterTwoDimensionalArray(int** a, int n, int m){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            cin >> a[t][i];
        }
    }
}

void fillRandomTwoDimensionalArray(int **a, int n, int m){
    srand(time(NULL));
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            a[t][i] = rand()%100;
        }
    }
}

void printTwoDimensionalArray(int **a, int n, int m){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            cout << a[t][i] << " ";
        }
        cout << endl;
    }
}

void printTwoDimensionalBooleanArray(bool **a, int n){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < n; i++){
            cout << a[t][i] << " ";
        }
        cout << endl;
    }
}

bool hasEqualElements(int **a, int n){
    bool hasEqual = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int m = 0; m < n; m++){
                    if (a[i][j] == a[k][m] && (i != k || j != m)){
                        hasEqual = true;
                    }
                }
            }
        }
    }
    return hasEqual;
}

void printFormattedTwoDimensionalArray(int **a, int n, int m, int width, ofstream& fout){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            fout << setw(width) << a[t][i];
        }
        fout << endl;
    }
}

int sumInRow(int **matrix, int n, int row){
    int sum = 0;
    for (int t = 0; t < n; t++){
        sum += matrix[row][t];
    }
    return sum;
}

int sumInColumn(int **matrix, int n, int column){
    int sum = 0;
    for (int t = 0; t < n; t++){
        sum += matrix[t][column];
    }
    return sum;
}

int sumInFirstDiagonal(int **matrix, int n){
    int sum = 0;
    for (int t = 0; t < n; t++){
        sum += matrix[t][t];
    }
    return sum;
}

int sumInSecondDiagonal(int **matrix, int n){
    int sum = 0;
    for (int t = 0; t < n; t++){
        sum += matrix[t][n-t-1];
    }
    return sum;
}
