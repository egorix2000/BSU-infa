/*Написать программу, которая вычисляет дату следующего дня. Например:
Введите цифрами сегодняшнюю дату (число месяц год) –> 30 4 2016
Вывести 30.04.2016


Egor Bychenok

input			output
-------------------------------
1 1 20			02.01.0020
28 2 2000		29.02.2000
28 2 2100		01.03.2100
31 12 2001		01.01.2002
30 12 2001		31.12.2001
29 2 2100		Incorrect day, there. Write day

Стремится к e
*/

#include <iostream>

using namespace std;


void main()
{
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day;
	int month;
	int year;
	cout << "enter day, month and year" << endl;
	cin >> day >> month >> year;
	while (year < 1) {
		cout << "year must be more than 0. Write year" << endl;
		cin >> year;
	}
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		daysInMonth[1] = 29;
	}
	while (month < 1 || month > 12) {
		cout << "month must be a number from 1 to 12. Write month" << endl;
		cin >> month;
	}
	while (day < 1 || day > daysInMonth[month-1]) {
		cout << "Incorrect day, there. Write day" << endl;
		cin >> day;
	}
	day++;
	if (day <= daysInMonth[month-1]) {
		if (day < 10) {
			cout << "0";
		}
		cout << day << ".";
		if (month < 10) {
			cout << "0";
		}
		cout << month << ".";
		if (year < 1000) {
			cout << "0";
		}
		if (year < 100) {
			cout << "0";
		}
		if (year < 10) {
			cout << "0";
		}
		cout << year << endl;
	}
	else {
		day = 1;
		month++;
		if (month <= 12) {
			if (day < 10) {
				cout << "0";
			}
			cout << day << ".";
			if (month < 10) {
				cout << "0";
			}
			cout << month << ".";
			if (year < 1000) {
				cout << "0";
			}
			if (year < 100) {
				cout << "0";
			}
			if (year < 10) {
				cout << "0";
			}
			cout << year << endl;
		}
		else {
			month = 1;
			year++;
			if (day < 10) {
				cout << "0";
			}
			cout << day << ".";
			if (month < 10) {
				cout << "0";
			}
			cout << month << ".";
			if (year < 1000) {
				cout << "0";
			}
			if (year < 100) {
				cout << "0";
			}
			if (year < 10) {
				cout << "0";
			}
			cout << year << endl;
		}
	}
	system("pause");
}