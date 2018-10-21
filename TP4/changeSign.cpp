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

using namespace std;

//change file paths to yours
ifstream fin("Downloads/A/tests/changeSign/input.txt");
ofstream fout("Downloads/A/tests/changeSign/output.txt");

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
        ans = changeSignInArray(oneDemensionalA, n*m);
        fout << ans << endl;
    }
    return 0;
}
