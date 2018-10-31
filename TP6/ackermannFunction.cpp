/**

Написать рекурсивную функцию для вычисления значения так называемой
функции Аккермана для неотрицательных чисел n и m
Функция Аккермана A(n, m) определяется следующим образом:
m + 1, если n = 0;
A(n, m) = А(n - 1, 1), если n ≠ 0, m = 0;
A(n - 1, A(n, m- 1)), если n >0, m >0.
**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/ackermannFunction/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/ackermannFunction/output.txt";

int findAckermannFunctionValue(int n, int m){
    int temp;
    if (n == 0){
        return m+1;
    }
    else if (m == 0){
        return findAckermannFunctionValue(n-1, 1);
    } else {
        temp = findAckermannFunctionValue(n, m - 1);
        return findAckermannFunctionValue(n - 1, temp);
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    int n;
    int m;
    int functionValue;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> n >> m){
            functionValue = findAckermannFunctionValue(n, m);
            fout << functionValue << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
