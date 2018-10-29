/**

Даны два слова. Для каждой буквы первого слова
а) в том числе для повторяющихся в этом слове букв
б) повторяющиеся буквы первого слова не рассматривать
определить, входит ли она во второе слово.

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
const char* INPUT_FILE = "Downloads/A/tests/matchingLetters/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/matchingLetters/output.txt";

int countLetters(char* s, int letters[]){
    for (int i = 0; i < strlen(s); i++){
        letters[(int) s[i] - (int) 'a']++;
    }
    return 0;
}

int printWithEqual(char* s, int letters1[], int letters2[], ofstream& fout){
    int currentLetter;
    for (int i = 0; i < strlen(s); i++){
        currentLetter = (int) s[i] - (int) 'a';
        if (letters1[currentLetter] > 0 && letters2[currentLetter] > 0){
            letters1[currentLetter]--;
            letters2[currentLetter]--;
            fout << "yes ";
        } else {
            fout << "no ";
        }
    }
    return 0;
}

int printWithoutEqual(char* s, int letters1[], int letters2[], ofstream& fout){
    int currentLetter;
    for (int i = 0; i < strlen(s); i++){
        currentLetter = (int) s[i] - (int) 'a';
        if (letters1[currentLetter] > 0 && letters2[currentLetter] > 0){
            letters1[currentLetter] = 0;
            letters2[currentLetter] = 0;
            fout << "yes ";
        } else if (letters1[currentLetter] > 0 || letters2[currentLetter] > 0) {
            letters1[currentLetter] = 0;
            letters2[currentLetter] = 0;
            fout << "no ";
        }
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    char word1[MAX_STRING_LENGTH];
    char word2[MAX_STRING_LENGTH];
    int letters1[ALPHABET_SIZE];
    int letters2[ALPHABET_SIZE];

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> word1 && fin >> word2){
            fillArrayWithZeros(letters1, ALPHABET_SIZE);
            fillArrayWithZeros(letters2, ALPHABET_SIZE);

            countLetters(word1, letters1);
            countLetters(word2, letters2);

            printWithEqual(word1, letters1, letters2, fout);
            fout << endl;

            fillArrayWithZeros(letters1, ALPHABET_SIZE);
            fillArrayWithZeros(letters2, ALPHABET_SIZE);

            countLetters(word1, letters1);
            countLetters(word2, letters2);

            printWithoutEqual(word1, letters1, letters2, fout);
            fout << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
