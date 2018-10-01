/* Дано трехзначное число.Найти:
а)	число единиц в нем;
б)	число десятков в нем;
в)	сумму его цифр;
г)	произведение его цифр.

Egor Bychenok

input			output
-------------------------------
125				units: 5
				tens: 2
				sum: 8
				mult: 10

100				units: 0
				tens: 0
				sum: 1
				mult: 0

3				Error! Number must contain 3 digits.

-274				units: 4
				tens: 7
				sum: 13
				mult: 56

*/

#include <iostream>

using namespace std;

void main()
{
	int n;
	int units;
	int hundreds;
	int tens;
	int sum;
	int mult = 1;
	cout << "write number" << endl;
	cin >> n;
	n = abs(n);
	if (n < 100 || n > 999) {
		cout << "Error! Number must contain 3 digits." << endl;
	}
	else {
		units = n % 10;
		tens = (n / 10) % 10;
		hundreds = n / 100;
		sum = units + tens + hundreds;
		mult = units * tens * hundreds;
		cout << "units: " << units << endl;
		cout << "tens: " << tens << endl;
		cout << "sum: " << sum << endl;
		cout << "mult: " << mult << endl;
	}
	system("pause");
}
