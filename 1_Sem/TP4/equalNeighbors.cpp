/**

Дан двумерный массив (n x m). Найти:
а) число пар одинаковых соседних элементов в каждой строке;
б) число пар одинаковых соседних элементов в каждом столбце.

**/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int findNumberOfEqualNeighborsInColumns(int** a, int n, int m){
    int ans = 0;
    //in columns
    for (int j = 0; j < m; j++){
        for (int i = 1; i < n; i++){
            if (a[i][j] == a[i-1][j]){
                ans++;
            }
        }
    }
    return ans;
}

int findNumberOfEqualNeighborsInRows(int** a, int n, int m){
    int ans = 0;
    //in rows
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] == a[i][j-1]){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    //change file paths to yours
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    int nTests;
    int equalInRows;
    int equalInColumns;
    int n, m;
    int** a;

    fin.open("Downloads/A/tests/equalNeighbors/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/equalNeighbors/output.txt");

        fin >> nTests;

        for (int j = 0; j < nTests; j++){
            fin >> n >> m;
            a = new int*[n];
            for (int i = 0; i < n; i++){
                a[i] = new int[m];
            }

            enterTwoDimensionalArrayFromFile(a, n, m, fin);

            equalInRows = findNumberOfEqualNeighborsInRows(a, n, m);
            equalInColumns = findNumberOfEqualNeighborsInColumns(a, n, m);
            fout << equalInRows << " " << equalInColumns << endl;
        }
    } else {
        cout << error << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
