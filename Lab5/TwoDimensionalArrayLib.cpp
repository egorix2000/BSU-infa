#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void enterTwoDimensionalArray(int **a, int n){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < n; i++){
            cin >> a[t][i];
        }
    }
}

void fillRandomTwoDimensionalArray(int **a, int n){
    srand(time(NULL));
    for (int t = 0; t < n; t++){
        for (int i = 0; i < n; i++){
            a[t][i] = rand()%100;
        }
    }
}

void printTwoDimensionalArray(int **a, int n){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < n; i++){
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

void printFormattedTwoDimensionalArray(int **a, int n, int width){
    for (int t = 0; t < n; t++){
        for (int i = 0; i < n; i++){
            cout << setw(width) << a[t][i];
        }
        cout << endl;
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
