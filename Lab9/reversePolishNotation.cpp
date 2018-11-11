/**

Дана строка, которая представляет собой исходное математическое выражение,
содержащее целые числа, операции +,  *, -, /  и скобки любой степени
вложенности. Перевести его в обратную польскую запись и вычислить
значение записанного выражения.

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
const char* INPUT_FILE = "Downloads/A/tests/reversePolishNotation/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/reversePolishNotation/output.txt";

bool isSpace (char c) {
    if (c == ' '){
        return true;
    } else {
        return false;
    }
}

bool isOperator (char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    } else {
        return false;
    }
}

int getOperatorPriority (char op) {
    if (op == '+' || op == '-'){
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return -1;
    }
}

void calc (Stack<int>& st, char op) {
	int r = st.getTop();
	st.pop();
	int l = st.getTop();
	st.pop();
	switch (op) {
		case '+':
		    st.push(l + r);
		    break;
		case '-':
		    st.push(l - r);
		    break;
		case '*':
		    st.push(l * r);
		    break;
		case '/':
		    st.push(l / r);
		    break;
	}
}

int getValueOfExpression (char* s) {
	Stack<int> st;
	Stack<char> op;
	for (int i = 0; i < strlen(s); i++){
		if (!isSpace(s[i])){
			if (s[i] == '('){
				op.push('(');
			}
			else if (s[i] == ')') {
				while (op.getTop() != '('){
					calc(st, op.getTop());
                    op.pop();
				}
				op.pop();
			}
			else if (isOperator(s[i])) {
				char currentOperator = s[i];
				while (!op.isEmpty() && getOperatorPriority(op.getTop()) >= getOperatorPriority(currentOperator)){
                    calc(st, op.getTop());
					op.pop();
				}
				op.push(currentOperator);
			}
			else {
				char number[MAX_STRING_LENGTH] = "";
				int k = 0;
				while (i < strlen(s) && isdigit(s[i])){
					number[k] = s[i];
					k++;
					i++;
				}
				i--;
				st.push(atoi(number));
			}
		}
	}
	while (!op.isEmpty()){
		calc (st, op.getTop());
        op.pop();
	}
	return st.getTop();
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char s[MAX_STRING_LENGTH];
    int value;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            value = getValueOfExpression(s);
            fout << value << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
