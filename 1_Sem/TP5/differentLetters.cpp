/**

Дан текст. В выходной файл записать только те буквы слов,
которые встречаются в словах текста только один раз. Например,
для текста процессор информация, то ответом должно быть: п е ф м а я

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"
#include "OneDimensionalArrayLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
const int ALPHABET_SIZE = 26;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/differentLetters/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/differentLetters/output.txt";

int tolower(char* s){
    for (int i = 0; i < strlen(s); i++){
        if (isalpha(s[i])){
            s[i] = tolower(s[i]);
        }
    }
    return 0;
}

int countLetters(char* s, int letters[]){
    for (int i = 0; i < strlen(s); i++){
        if (isalpha(s[i])){
            letters[(int) s[i] - (int) 'a']++;
        }
    }
    return 0;
}

int printDifferentLetters(char* s, int letters[], ofstream& fout){
    int currentLetter;
    for (int i = 0; i < strlen(s); i++){
        if (isalpha(s[i])){
            currentLetter = (int) s[i] - (int) 'a';
            if (letters[currentLetter] > 0){
                letters[currentLetter] = 0;
                fout << s[i] << " ";
            }
        }
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    char s[MAX_STRING_LENGTH];
    int letters[ALPHABET_SIZE];

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            tolower(s);
            fillArrayWithZeros(letters, ALPHABET_SIZE);

            countLetters(s, letters);

            printDifferentLetters(s, letters, fout);
            fout << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
