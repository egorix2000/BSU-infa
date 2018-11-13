/**

Рациональная (несократимая) дробь представляется парой целых чисел (a,b), где a – числитель,
b – знаменатель. Создать класс Rational для работы с рациональными дробями. Реализовать
конструкторы: копирования и инициализации, а также методы:
	•	сложение add, (a,b) + (c,d) = (ad+bc,bd);
	•	умножение mul, (a,b) * (c,d) = (ac, bd);
	•	деление div, (a,b)/(c,d) = (ad,bc);
	•	сравнение equal, greater, less;
	•	вывод print.
Зам. Реализовать приватную функцию сокращения дроби reduce, которая обязательно вызывается при выполнении арифметических операций.

**/

#include <iostream>
#include <fstream>

#include "RationalFraction.h"
#include "FileLib.h"

using namespace std;



void testRationalNumbers(){
    RationalFraction a, b, c, d;
    a.setNumerator(2);
    a.setDenominator(4);
    b.setNumerator(5);
    b.setDenominator(3);
    c.setNumerator(6);
    c.setDenominator(7);
    d.setNumerator(2);
    d.setDenominator(1);

    a.add(b);
    cout << "a += b: ";
    a.print();

    b.mult(c);
    cout << "b *= c: ";
    b.print();

    c.div(d);
    cout << "c /= d: ";
    c.print();

    if (a.compare(b) > 0){
        cout << "a greater than b" << endl;
    } else if (a.compare(b) < 0){
        cout << "a less than b" << endl;
    } else {
    cout << "a equal b" << endl;
    }

    if (b.compare(a) > 0){
        cout << "b greater than a" << endl;
    } else if (b.compare(a) < 0){
        cout << "b less than a" << endl;
    } else {
    cout << "b equal a" << endl;
    }

    if (b.compare(b) > 0){
        cout << "b greater than b" << endl;
    } else if (a.compare(b) < 0){
        cout << "b less than b" << endl;
    } else {
        cout << "b equal b" << endl;
    }
}

int main()
{
    testRationalNumbers();
    return 0;
}
