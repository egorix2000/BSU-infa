/**

Удалить из строки заданное слово.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int removeSubstr(char* s, char* word, char* pCurrentWord){
    char newS[MAX_STRING_LENGTH] = "";
    strncpy(newS, s, pCurrentWord - s);
    strcat(newS, pCurrentWord + strlen(word));
    strcpy(s, newS);
    return 0;
}

int removeAllSubstr(char* s, char* word){
    char* pCurrentWord;
    pCurrentWord = strstr(s, word);
    while (pCurrentWord != NULL){
        removeSubstr(s, word, pCurrentWord);
        pCurrentWord = strstr(s, word);
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
    char word[MAX_STRING_LENGTH];

    fin.open("Downloads/A/tests/wordRemove/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/wordRemove/output.txt");

        while (fin.getline(s, MAX_STRING_LENGTH)){
            fin.getline(word, MAX_STRING_LENGTH);
            removeAllSubstr(s, word);
            fout << s << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
