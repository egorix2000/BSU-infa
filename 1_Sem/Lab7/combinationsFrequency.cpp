/**
Дана строка. Посчитать в ней частоты всех двухбуквенных сочетаний без учета регистра и без учета символов, не являющихся буквами.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int printCombinationsFrequency(ofstream& fout, int a[26][26]){
    fout << "  ";
    for (int i = 0; i < 26; i++){
        fout << (char) ( (int) 'a' + i) << " ";
    }
    fout << endl;
    for (int i = 0; i < 26; i++){
        fout << (char) ( (int) 'a' + i) << " ";
        for (int j = 0; j < 26; j++){
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
    return 0;
}

int fillCombinationsFrequency(int a[26][26]){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            a[i][j] = 0;
        }
    }
    return 0;
}

int main()
{
    //change file paths to yours
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    char s[MAX_STRING_LENGTH];
    char previous;
    char current;
    int combinationsFrequency[26][26];

    fin.open("Downloads/A/tests/combinationsFrequency/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/combinationsFrequency/output.txt");

        while (fin.getline(s, MAX_STRING_LENGTH)){
            fillCombinationsFrequency(combinationsFrequency);
            previous = '0';
            current = '0';
            for (int i = 0; i < strlen(s); i++){
                if(isalpha(s[i])){
                    tolower(s[i]);
                    if (previous == '0'){
                        previous = s[i];
                    } else if (current == '0'){
                        current = s[i];
                        combinationsFrequency[(int) previous - (int) 'a'][(int) current - (int) 'a']++;
                    } else {
                        previous = current;
                        current = s[i];
                        combinationsFrequency[(int) previous - (int) 'a'][(int) current - (int) 'a']++;
                    }
                }
            }
            printCombinationsFrequency(fout, combinationsFrequency);
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
