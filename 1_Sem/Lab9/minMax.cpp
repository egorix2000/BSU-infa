/**

Пусть дана без ошибок формула, имеющая следующий синтаксис:
<формула>::=<цифра> | max(<формула>, < формула >) | min (<формула>,< формула >)
<цифра>::=0  1  2  3  4  5  6  7  8   9
Например, 8 или max(4, min(3, 5)) или  min(min(3, 5), max(2, max(3, 4))).
Вычислить значение формулы, используя структуру данных стек.


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
const char* INPUT_FILE = "Downloads/A/tests/minMax/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/minMax/output.txt";
int MIN = -1;
int MAX = 10;

int findMin(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int findMax(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int findValueOfExpression(char* s, Stack<int> expression){
    int ans;
    int temp1;
    int temp2;
    int temp3;
    for (int i = 0; i < strlen(s); i++){
        if (isdigit(s[i])){
            expression.push(s[i]-'0');
        } else if (s[i] == '('){
            if (s[i-2] == 'i'){ // min
                expression.push(MIN);
            } else { // max
                expression.push(MAX);
            }
        } else if (s[i] == ')') {
            temp1 = expression.getTop();
            expression.pop();
            temp2 = expression.getTop();
            expression.pop();
            if (expression.getTop() == MIN){
                temp3 = findMin(temp1, temp2);
            } else {
                temp3 = findMax(temp1, temp2);
            }
            expression.pop();
            expression.push(temp3);
        }
    }
    ans = expression.getTop();
    return ans;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char s[MAX_STRING_LENGTH];
    Stack<int> expression;
    int ans;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            ans = findValueOfExpression(s, expression);
            fout << ans << endl;
        }

    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
