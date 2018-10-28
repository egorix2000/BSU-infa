/**

Дана строка символов. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int main()
{
    //change file paths to yours
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    int counterDigits;
    int counterLetters;
    int counterOtherSymbols;
    char s[MAX_STRING_LENGTH];

    fin.open("Downloads/A/tests/digitsNumbersOtherSymbols/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/digitsNumbersOtherSymbols/output.txt");

        while (fin.getline(s, MAX_STRING_LENGTH)){
            counterOtherSymbols = 0;
            counterDigits = 0;
            counterLetters = 0;
            for (int t = 0; t < strlen(s); t++){
                if (isdigit(s[t])){
                    counterDigits++;
                } else if (isalpha(s[t])){
                    counterLetters++;
                } else {
                    counterOtherSymbols++;
                }
            }
            fout << counterDigits << ' ' << counterLetters << ' ' << counterOtherSymbols << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
