/**
Реализовать 4 функции. Добавьте меню, в котором пользователь может выбрать желаемую операцию:
	•	Создать функцию, вставляющую строку в двумерный динамический массив в указанную позицию.
	•	Создать функцию, вставляющую столбец в двумерный динамический массив в указанную позицию.
	•	Создать функцию, удаляющую заданную строку двумерного динамического массива.
	•	Создать функцию, удаляющую заданный столбец двумерного динамического массива.

-----------------------------------------
input

4 5
 97 50 46 53 71
 44 25 49 71 39
 43 12 41 53 66
 63 56 72 56 49
0 1

output

 18  9 68 85 19
 97 50 46 53 71
 44 25 49 71 39
 43 12 41 53 66
 63 56 72 56 49
-----------------------------------------
input

1 1
 16
1 1

output

 16
 31
-----------------------------------------
input

4 5
 73 48 41 78 28
  1 41 95 77 72
 55 96 17 27 59
 84 81 50 21  1
1 2

output

 73 32 48 41 78 28
  1 49 41 95 77 72
 55 27 96 17 27 59
 84 82 81 50 21  1
-----------------------------------------
input

4 5
 72 65 81 62 28
 41  8  8 55 94
  1 38 52 27 77
 45 34  3 14 44
0 3

output

 41  8  8 55 94
  1 38 52 27 77
 45 34  3 14 44
-----------------------------------------
input

6 2
 52 90
 91 89
 94 98
 74 59
  6 68
 49 51
1 4

output

 52
 91
 94
 74
  6
 49
-----------------------------------------
**/


#include <iostream>
#include <iomanip>
#include <ctime>
#include "TwoDimensionalArrayLib.h"

using namespace std;


int** insertRow(int** a, int& n, int& m, int pos){
    int** newA = new int*[n+1];
    for (int i = 0; i < n+1; i++){
        newA[i] = new int[m];
    }
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m; j++){
            if (i < pos){
                newA[i][j] = a[i][j];
            } else if (i > pos){
                newA[i][j] = a[i-1][j];
            } else {
                newA[i][j] = rand()%100;
            }
        }
    }
    n++;
    return newA;
}

int** insertColumn(int** a, int& n, int& m, int pos){
    int** newA = new int*[n];
    for (int i = 0; i < n; i++){
        newA[i] = new int[m+1];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m+1; j++){
            if (j < pos){
                newA[i][j] = a[i][j];
            } else if (j > pos){
                newA[i][j] = a[i][j-1];
            } else {
                newA[i][j] = rand()%100;
            }
        }
    }
    m++;
    return newA;
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

int** controller(int** a, int& n, int& m, int pos, int** (*func) (int**, int&, int&, int)){
    return func(a, n, m, pos);
}

int main()
{
    srand(time(NULL));
    int n;
    int m;
    int index;
    int** a;
    int choice;
    int** (*func) (int**, int&, int&, int);
    cout << "Enter matrix size" << endl;
    cin >> n >> m;
    a = new int*[n];
    for (int i = 0; i < n; i++){
        a[i] = new int[m];
    }
    fillRandomTwoDimensionalArray(a, n, m);
    printFormattedTwoDimensionalArray(a, n, m, 3);

    cout << "Enter where to insert/delete row/column" << endl;
    cin >> index;
    cout << "Enter: "<< endl << "'1' to add row"
                     << endl << "'2' to add column"
                     << endl << "'3' to delete row"
                     << endl << "'4' to delete column"
                     << endl << "'0' to exit" << endl;
    cin >> choice;

    while(choice != 0){
        switch(choice){
        case 1:
            {
                func = &insertRow;
                break;
            }
        case 2:
            {
                func = &insertColumn;
                break;
            }
        case 3:
            {
                func = &deleteRow;
                break;
            }
        case 4:
            {
                func = &deleteColumn;
                break;
            }
        default:
            func = &insertRow;
        }
        a = controller(a, n, m, index, func);
        printFormattedTwoDimensionalArray(a, n, m, 3);
        cout << "Enter where to insert/delete row/column" << endl;
        cin >> index;
        cout << "Enter: "<< endl << "'1' to add row"
                     << endl << "'2' to add column"
                     << endl << "'3' to delete row"
                     << endl << "'4' to delete column"
                     << endl << "'0' to exit" << endl;
        cin >> choice;
    }
    return 0;
}
