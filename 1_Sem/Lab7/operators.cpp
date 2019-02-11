/**

Дан код программы на С++.  Вывести построчно все операции и частоту их использования в программе.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"
#include "OneDimensionalArrayLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
const int N_OPERATORS = 33;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/operations/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/operations/output.txt";

int replaceWithZeros(char* position, int length){
    for (int i = 0 ; i < length; i++){
        position[i] = 0;
    }
    return 0;
}

int countAllOperators (char* s, char operators[N_OPERATORS][MAX_STRING_LENGTH], int operatorsCount[N_OPERATORS]){
    char* currentOperator;
    for (int i = 0; i < N_OPERATORS; i++){
        currentOperator = strstr(s, operators[i]);
        while(currentOperator){
            operatorsCount[i]++;
            replaceWithZeros(currentOperator, strlen(operators[i]));
            currentOperator = strstr(s, operators[i]);
        }
    }
    return 0;
}

int print(char operators[N_OPERATORS][MAX_STRING_LENGTH], int operatorsCount[N_OPERATORS], ofstream& fout){
    for (int t = 0; t < N_OPERATORS; t++){
        fout << operators[t] << " : " << operatorsCount[t] << endl;
    }
    return 0;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char operators[N_OPERATORS][MAX_STRING_LENGTH] = {
                ">>=", "<<=", "++", "--", "&&", "||", ">>", "<<",
                "==", "!=", "<=", ">=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
                "=", "+", "-", "*", "/", "%", ">", "<", "!", "~", "&", "|", "^"};
    int operatorsCount[N_OPERATORS];
    char error[MAX_STRING_LENGTH];
    char s[MAX_STRING_LENGTH];

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        fillArrayWithZeros(operatorsCount, N_OPERATORS);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            countAllOperators(s, operators, operatorsCount);
        }
        print(operators, operatorsCount, fout);
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
