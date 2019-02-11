/**

Написать рекурсивную функцию нахождения цифрового корня натурального числа.
Цифровой корень данного числа получается следующим образом: если сложить
все цифры этого числа, затем все цифры найденной суммы и повторять этот
процесс, то в результате будет получено однозначное число (цифра),
которая и называется цифровым корнем данного числа.
Например: 15 634 -> 19 ->10 -> 1

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/digitRoot/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/digitRoot/output.txt";

int findDigitRoot(int n){
    int newN = 0;
    if (n < 10){
        return n;
    }
    while (n > 0){
        newN += n%10;
        n /= 10;
    }
    return findDigitRoot(newN);
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    int n;
    int digitRoot;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> n){
            digitRoot = findDigitRoot(n);
            fout << digitRoot << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
