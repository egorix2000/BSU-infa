/**
Реализовать 4 функции на простейшие арифметические операции (+, -, *, /).
Каждая функция должна принимать два вещественных числа и возвращать
результат операции в виде вещественного числа. Напишите функцию,
которая принимает указатель на функцию в качестве параметра.
Добавьте меню, в котором пользователь может выбрать
желаемую операцию.

input			            output
-----------------------------------------

5 3 -                       2

3 5 -                       -2

2 3 +                       5

0 5 *                       0

3 5 *                       15

4 2 /                       2

7 2 /                       3.5

2 7 /                       0.285714

**/


#include <iostream>

using namespace std;

double mySum (double a, double b) {
    return a + b;
}

double myDifference (double a, double b) {
    return a - b;
}

double myMult (double a, double b) {
    return a * b;
}

double myDev (double a, double b) {
    return a / b;
}

double operate(double a, double b, double (*func) (double, double)){
    return func(a, b);
}

int main()
{
    double a;
    double b;
    char c;
    double (*func) (double, double);
    cout << "Enter a and b" << endl;
    cin >> a >> b;
    cout << "Enter one of operations: + - * /" << endl;
    cout << "Print 0 to exit" << endl;
    cin >> c;
    while (c != '0'){
        switch(c){
        case '+':
            {
                func = &mySum;
                break;
            }
        case '-':
            {
                func = &myDifference;
                break;
            }
        case '*':
            {
                func = &myMult;
                break;
            }
        case '/':
            {
                func = &myDev;
                break;
            }
        default:
            func = &mySum;
        }
        cout << operate(a, b, func) << endl;
        cout << "Enter a and b" << endl;
        cin >> a >> b;
        cout << "Enter one of operations: + - * /" << endl;
        cout << "Print 0 to exit" << endl;
        cin >> c;
    }
    return 0;
}
