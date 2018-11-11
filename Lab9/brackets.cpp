/**

Дано математическое выражение в виде строки символов. Напишите программу,
которая определит, правильно ли расставлены скобки в выражении, если оно
состоит из скобок типа: ( ) [ ] { }. (использовать структуру данных стек).

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

#include "Stack.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/brackets/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/brackets/output.txt";

bool isCorrect(char* s, Stack<char> brackets){
    bool isCorrect = true;
    for (int i = 0; i < strlen(s); i++){
        if (isCorrect){
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    brackets.push(s[i]);
                    break;
                case ')':
                    if (brackets.getTop() != '('){
                        isCorrect = false;
                    }
                    brackets.pop();
                    break;
                case '}':
                    if (brackets.getTop() != '{'){
                        isCorrect = false;
                    }
                    brackets.pop();
                    break;
                case ']':
                    if (brackets.getTop() != '['){
                        isCorrect = false;
                    }
                    brackets.pop();
                    break;
            }
        }
    }
    return isCorrect;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char s[MAX_STRING_LENGTH];
    Stack<char> brackets;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            if (isCorrect(s, brackets)){
                fout << "Yes" << endl;
            } else {
                fout << "No" << endl;
            }
        }

    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
