/**

Дан двумерный массив (n x m). Определить количество различных элементов в нем.

**/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"
#include "OneDimensionalArrayLib.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

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
    //change file paths to yours
    ifstream fin;
    ofstream fout;
    int nTests;
    int ans;
    int n, m;
    int** a;
    int* oneDemensionalA;
    char error[MAX_STRING_LENGTH];

    fin.open("Downloads/A/tests/differentNumbers/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/differentNumbers/output.txt");
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
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
