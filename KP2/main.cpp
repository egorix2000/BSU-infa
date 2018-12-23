/*
1. Разработать шаблон класса Stack.

2. Разработать шаблон класса «Многочлен» – Polynomial степени n .
 Написать несколько конструкторов, в том числе конструктор копирования.
 Реализовать методы для вычисления значения полинома; сложения, вычитания.
 Перегрузить операции сложения, вычитания, индексирования, присваивания.

3. Прочитать коэффициенты нескольких полиномов из файла.
 Создать стек объектов класса. Передать его в функцию,
 вычисляющую сумму полиномов четной степени и возвращающую
 полином-результат, который выводится на экран в головной программе.
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>
#include "FileLib.h"
#include "Stack.h"
#include "Vector.h"
#include "Polynomial.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

void calculate(Stack< Polynomial<int> >& stack, Polynomial<int>& ans) {
    while (!stack.isEmpty()) {
        if (stack.getTop().getDegree() % 2 == 1) {
            ans += stack.getTop();
        }
        stack.pop();
    }
}

int main()
{
    string file;
    string polynomialString;
    string s;
    string stringCoefficient;
    Vector<int>* v = new Vector<int>();
    Stack< Polynomial<int> >* stack = new Stack< Polynomial<int> >();
    Polynomial<int>* item = 0;
    Polynomial<int>* ans = new Polynomial<int>();
    int coefficient;
    ifstream fin;
    char error[MAX_STRING_LENGTH];

    cout << "Enter filename with full path: " << endl;
    cin >> file;

    fin.open(file);

    if(validateFile(fin, error)) {
        while (getline(fin, s)) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' '){
                    coefficient = atoi(stringCoefficient.c_str());
                    v->push_back(coefficient);
                    stringCoefficient = "";
                } else {
                    stringCoefficient += s[i];
                }
            }
            coefficient = atoi(stringCoefficient.c_str());
            v->push_back(coefficient);
            stringCoefficient = "";
            item = new Polynomial<int>(*v);
            stack->push(*item);
            s = "";
            v->reset();
        }
    } else {
        cout << error << endl;
    }

    calculate(*stack, *ans);

    if (ans->getDegree() != 0) {
        for (int i = 0; i < ans->getDegree(); i++) {
            cout << (*ans)[i] << " ";
        }
    } else {
        cout << "0";
    }

    cout << endl;

    delete v;
    delete stack;
    if (item != 0) {
        delete item;
    }
    delete ans;

    fin.close();
    return 0;
}
