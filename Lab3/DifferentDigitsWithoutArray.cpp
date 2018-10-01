/*Найти количество различных цифр в записи заданного натурального числа n (разработать алгоритмы с использованием и без использования массивов).

Egor Bychenok

input			output
-------------------------------
1				1
11				1
1544			3
0				number must be more than 0. Write number

*/

#include <iostream>

using namespace std;

long long n;

void numInput() {
	cout << "Enter number" << endl;
	cin >> n;
}

void validateNumber() {
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
}

long long differentDigits() {
	long long copyN;
	long long ans = 0;
	while (n > 0) {
		ans++;
		copyN = n;
		copyN /= 10;
		while (copyN > 0) {
			if (copyN % 10 == n % 10) {
				ans--;
				break;
			}
			copyN /= 10;
		}
		n /= 10;
	}
	return ans;
}

void main()
{
	numInput();
	validateNumber();

	cout << differentDigits() << endl;
	system("pause");
}