/**

Дан текст. Посчитать частоту слов в тексте.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
const int MAX_WORD_LENGTH = 128;
const int MAX_WORD_COUNT = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/wordsFrequency/input5.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/wordsFrequency/output5.txt";

int tolower(char* s){
    for (int i = 0; i < strlen(s); i++){
        if (isalpha(s[i])){
            s[i] = tolower(s[i]);
        }
    }
    return 0;
}

int findWord(char* word, char differentWords[MAX_WORD_COUNT][MAX_WORD_LENGTH], int wordsCount){
    int wordIndex = -1;
    for (int t = 0; t < wordsCount; t++){
        if (strcmp(word, differentWords[t]) == 0){
            wordIndex = t;
            break;
        }
    }
    return wordIndex;
}

int print(char differentWords[MAX_WORD_COUNT][MAX_WORD_LENGTH], int differentWordsCount[MAX_WORD_COUNT], int wordsCount, ofstream& fout){
    for (int i = 0; i < wordsCount; i++){
        fout << differentWords[i] << " : " << differentWordsCount[i] << endl;
    }
    return 0;
}

int findDifferentWords(char* s, char* separators, char differentWords[MAX_WORD_COUNT][MAX_WORD_LENGTH], int differentWordsCount[MAX_WORD_COUNT], int &wordsCount){
    char* currentWord = strtok (s, separators);
    int currentWordIndex = 0;
    while (currentWord != NULL){
        currentWordIndex = findWord(currentWord, differentWords, wordsCount);
        if (currentWordIndex >= 0){ // такое слово было
            differentWordsCount[currentWordIndex]++;
        } else {  // такого слова не было
            //differentWords[wordsCount] = currentWord;
            strcpy(differentWords[wordsCount], currentWord);
            differentWordsCount[wordsCount] = 1;
            wordsCount++;
        }
        currentWord = strtok (NULL, separators);
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char separators[] = " ,.-!?:;";
    char s[MAX_STRING_LENGTH];

    char differentWords[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    int differentWordsCount[MAX_WORD_COUNT];

    int wordsCount = 0;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            tolower(s);
            findDifferentWords(s, separators, differentWords, differentWordsCount, wordsCount);
        }
        print(differentWords, differentWordsCount, wordsCount, fout);

    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
