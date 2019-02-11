/**

Написать рекурсивную функцию для вычисления индекса максимального элемента массива из n элементов.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"
#include "OneDimensionalArrayLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/maxInArray/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/maxInArray/output.txt";

int findMax(int* a, int maxValue, int maxIndex, int currentIndex, int n){
    if (currentIndex >= n){
        return maxIndex;
    }
    if (a[0] > maxValue || maxIndex < 0){
        maxValue = a[0];
        maxIndex = currentIndex;
    }
    return findMax(a+1, maxValue, maxIndex, currentIndex+1, n);
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    int n;
    int iMax;
    int* a;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> n){
            a = new int[n];
            readArrayFromFile(a, n, fin);

            iMax = findMax(&a[0], 0, -1, 0, n);
            fout << iMax << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
