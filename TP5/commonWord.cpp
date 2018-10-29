/**

Дан текст, состоящий из предложений. Найти слово, которое встречается во всех предложениях текста, или сообщить, что такого слова нет.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
const int MAX_WORD_LENGTH = 128;
const int MAX_SENTENCE_COUNT = 256;
const int MAX_WORD_COUNT = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/commonWord/input1.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/commonWord/output1.txt";

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

int findDifferentWords(char* s, char* separators, char differentWords[MAX_WORD_COUNT][MAX_WORD_LENGTH], int &wordsCount){
    int currentWordIndex = 0;
    char* currentWord = strtok (s, separators);
    while (currentWord != NULL){
        currentWordIndex = findWord(currentWord, differentWords, wordsCount);
        if (currentWordIndex < 0){
            strcpy(differentWords[wordsCount], currentWord);
            wordsCount++;
        }
        currentWord = strtok (NULL, separators);
    }
    return 0;
}

int fillBoolArray(bool a[], int n, bool value){
    for (int i = 0; i < n; i++){
        a[i] = value;
    }
    return 0;
}

int print(char differentWordsInFirstSentence[MAX_WORD_COUNT][MAX_WORD_LENGTH], int wordsCount, ofstream& fout){
    bool doesCommonExist = false;
    for (int i = 0; i < wordsCount; i++){
        if (strcmp(differentWordsInFirstSentence[i], "") != 0){
            fout << differentWordsInFirstSentence[i] << endl;
            doesCommonExist = true;
        }
    }
    if (!doesCommonExist){
        fout << "Word doesn't exist" << endl;
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char wordSeparators[] = " ,.-!?:;";
    char sentenceSeparators[] = ".!?";
    char s[MAX_STRING_LENGTH];

    char sentences[MAX_SENTENCE_COUNT][MAX_STRING_LENGTH];
    int sentenceCount = 0;

    char differentWordsInFirstSentence[MAX_WORD_COUNT][MAX_WORD_LENGTH];
    bool areCommonDifferentWords[MAX_WORD_COUNT];

    char* currentWord;
    char* currentSentense;
    int currentWordIndex;
    int wordsCount = 0;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            tolower(s);

            // заносим в массив все строки
            currentSentense = strtok (s, sentenceSeparators);
            while (currentSentense != NULL){
                strcpy(sentences[sentenceCount], currentSentense);
                strcpy(sentences[sentenceCount+1], "");
                sentenceCount++;
                currentSentense = strtok (NULL, sentenceSeparators);
            }
            //находим все разные слова в первом предложении
            findDifferentWords(sentences[0], wordSeparators, differentWordsInFirstSentence, wordsCount);
            if (strcmp(sentences[1], "") == 0){ // если второго предложения нет, то все слова подходят
                fillBoolArray(areCommonDifferentWords, wordsCount, true);
            } else {
                for (int i = 1; i < sentenceCount; i++){
                    fillBoolArray(areCommonDifferentWords, wordsCount, false);
                    currentWord = strtok (sentences[i], wordSeparators);
                    while (currentWord != NULL){
                        currentWordIndex = findWord(currentWord, differentWordsInFirstSentence, wordsCount);
                        if (currentWordIndex >= 0){
                            areCommonDifferentWords[currentWordIndex] = true;
                        }
                        currentWord = strtok (NULL, wordSeparators);
                    }

                    for (int i = 0; i < wordsCount; i++){
                        if (!areCommonDifferentWords[i]){
                            strcpy(differentWordsInFirstSentence[i], "");
                        }
                    }
                }
            }
        }
        print(differentWordsInFirstSentence, wordsCount, fout);

    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
