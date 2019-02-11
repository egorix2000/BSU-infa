/**

В данной строке все вхождения подстроки str1 заменить подстрокой str2.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/replaceSubstr/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/replaceSubstr/output.txt";

int replaceSubstr(char* currentSubstrToReplace, char* s1, char* s2){
    int shift = strlen(s1) - strlen(s2);
    int k;
    if (shift < 0){
        shift *= (-1);
        for (int i = strlen(currentSubstrToReplace)-1; i >= 0; i--){
            currentSubstrToReplace[i+shift] = currentSubstrToReplace[i];
        }
    } else if (shift > 0) {
        k = shift;
        while (currentSubstrToReplace[k] != '\0'){
            currentSubstrToReplace[k - shift] = currentSubstrToReplace[k];
            k++;
        }
        currentSubstrToReplace[k - shift] = currentSubstrToReplace[k];
        k++;
        for (int i = 0; i < shift; i++){
            currentSubstrToReplace[k+i] = '\0';
        }
    }

    for (int i = 0; i < strlen(s2); i++){
        currentSubstrToReplace[i] = s2[i];
    }
    return 0;
}

int replaceAllSubstr(char* s, char* s1, char* s2){
    char* currentSubst;
    currentSubst = strstr(s, s1);
    while(currentSubst){
        replaceSubstr(currentSubst, s1, s2);
        currentSubst = strstr(s, s1);
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    char s[MAX_STRING_LENGTH];
    char s1[MAX_STRING_LENGTH];
    char s2[MAX_STRING_LENGTH];

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            fin.getline(s1, MAX_STRING_LENGTH);
            fin.getline(s2, MAX_STRING_LENGTH);
            replaceAllSubstr(s, s1, s2);
            fout << s << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
