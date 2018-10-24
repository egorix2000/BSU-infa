/**
Дан двумерный массив ненулевых целых чисел (n x m).
Определить, сколько раз элементы массива меняют знак
(принимая, что массив просматривается построчно сверху вниз, а в каждой строке – слева направо).

**/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"
#include "OneDimensionalArrayLib.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int changeSignInArray(int* a, int n){
    int ans = 0;
    for (int t = 1; t < n; t++){
        if ( (a[t] > 0 && a[t-1] < 0) || (a[t] < 0 && a[t-1] > 0) ){
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
    char error[MAX_STRING_LENGTH];
    int nTests;
    int ans;
    int n, m;
    int** a;
    int* oneDemensionalA;

    fin.open("Downloads/A/tests/changeSign/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/changeSign/output.txt");

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
            ans = changeSignInArray(oneDemensionalA, n*m);
            fout << ans << endl;
        }
    } else {
        cout << error << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
