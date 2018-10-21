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

using namespace std;

//change file paths to yours
ifstream fin("Downloads/A/tests/equalNeighbors/input.txt");
ofstream fout("Downloads/A/tests/equalNeighbors/output.txt");

int findNumberOfEqualNeighbors(int** a, int n, int m){
    int ans = 0;

    //in rows
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] == a[i][j-1]){
                ans++;
            }
        }
    }

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

int main()
{
    srand(time(NULL));
    int nTests;
    int ans;
    int n, m;
    int** a;
    fin >> nTests;

    for (int i = 0; i < nTests; i++){
        fin >> n >> m;
        a = new int*[n];
        for (int i = 0; i < n; i++){
            a[i] = new int[m];
        }

        enterTwoDimensionalArrayFromFile(a, n, m, fin);

        ans = findNumberOfEqualNeighbors(a, n, m);
        fout << ans << endl;
    }
    return 0;
}
