/**

Дана строка. «Перевернуть» в строке все слова (например: «Жили были дед и баба» - «илиЖ илыб дед и абаб»). Зам. Исходную строку не менять

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/wordReverse/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/wordReverse/output.txt";

int reverseWord(char* word){
    char temp;
    for (int t = 0; t < strlen(word)/2; t++){
        temp = word[t];
        word[t] = word[strlen(word)-t-1];
        word[strlen(word)-t-1] = temp;
    }
    return 0;
}

int reverseAllWords(char* s, char* reversedString){
    char *word = strtok (s, " ");

    while (word != NULL)
    {
        reverseWord(word);
        strcat(reversedString, word);
        strcat(reversedString, " ");
        word = strtok (NULL, " ");
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    char s[MAX_STRING_LENGTH];
    char sCopy[MAX_STRING_LENGTH];
    char reversedS[] = "";
    char emptyString[] = "";

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            strcpy(sCopy, s);
            strcpy(reversedS, emptyString);
            reverseAllWords(sCopy, reversedS);
            fout << reversedS << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
