/**
Дан двумерный массив (n x m). Определить количество различных элементов в нем.

**/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"
#include "OneDimensionalArrayLib.h"

using namespace std;

//change file paths to yours
ifstream fin("Downloads/A/tests/differentNumbers/input.txt");
ofstream fout("Downloads/A/tests/differentNumbers/output.txt");

int differentNumbersInSortedArray(int* a, int n){
    int ans = 1;
    for (int t = 1; t < n; t++){
        if (a[t] != a[t-1]){
            ans++;
        }
    }
    return ans;
}

int main()
{
    srand(time(NULL));
    int nTests;
    int ans;
    int n, m;
    int** a;
    int* oneDemensionalA;
    fin >> nTests;

    for (int i = 0; i < nTests; i++){
        fin >> n >> m;
        a = new int*[n];
        for (int i = 0; i < n; i++){
            a[i] = new int[m];
        }
        oneDemensionalA = new int[n*m];
        enterTwoDimensionalArrayFromFile(a, n, m, fin);
        translateIntoOneDemencionalArray(a, oneDemensionalA, n, m);
        sortArray(oneDemensionalA, n*m);
        ans = differentNumbersInSortedArray(oneDemensionalA, n*m);
        fout << ans << endl;
    }
    return 0;
}
