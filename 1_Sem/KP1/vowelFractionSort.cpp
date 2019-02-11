/**
Вариант 1
Дан текст, состоящий из предложений. Найти слово, которое встречается во всех предложениях текста, или сообщить, что такого слова нет.
Быченок Егор

tests in folder "tests"
**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
const int MAX_WORD_COUNT = 1024;
const char VOVELS[] = "eyuioaEYUIOA";

//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/vowelFractionSort/input1.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/vowelFractionSort/output1.txt";

struct wordWithVovelFraction{
    char word[MAX_STRING_LENGTH];
    double vovelFraction;
};

bool isVovel(char c){
    bool isVovel = false;
    if (strchr(VOVELS, c)){
        isVovel = true;
    }
    return isVovel;
}

double findVowelFraction(char* s){ //находим долю гласных
    double fraction = 0;
    for (int i = 0; i < strlen(s); i++){
        if (isVovel(s[i])){
            fraction++;
        }
    }

    fraction /= strlen(s);
    return fraction;
}

bool comparator(wordWithVovelFraction a, wordWithVovelFraction b){
    if (a.vovelFraction > b.vovelFraction){
        return false;
    } else {
        return true;
    }
}

void swapElements(wordWithVovelFraction &a, wordWithVovelFraction& b){
    wordWithVovelFraction *temp = new wordWithVovelFraction;
    *temp = a;
    a = b;
    b = *temp;
    delete temp;
}


void sortArray(wordWithVovelFraction *a, int n){
    int minIndex;

    for (int t = 0; t < n-1; t++){
        minIndex = t;
        for (int i = t+1; i < n; i++){
            if (comparator(a[minIndex], a[i])){
                minIndex = i;
            }
        }
        if (minIndex != t){
            swapElements(a[t], a[minIndex]);
        }
    }
}
int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    wordWithVovelFraction words[MAX_WORD_COUNT];
    int wordsCount = 0;


    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> words[wordsCount].word){ // ввод
            wordsCount++;
        }

        for (int i = 0; i < wordsCount; i++){
            words[i].vovelFraction = findVowelFraction(words[i].word);
        }

        sortArray(&words[0], wordsCount);

        for (int i = 0; i < wordsCount; i++){
            fout << words[i].word << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
