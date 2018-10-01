/*Ќайти все натуральные числа, не превосход€щие заданного числа n, у которых все цифры в записи числа различны.

Egor Bychenok

input			output
-------------------------------
5				5
12				11
265				207
0				number must be more than 0. Write number

*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> digits;

int numInput() {
	int n;
	cout << "Enter number" << endl;
	cin >> n;
	return n;
}

int validateNumber(int n1) {
	int n = n1;
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
	return n;
}

bool checkNumber(int n){
	while (n > 0) {
		if (digits[n % 10]) {
			return false;
		} else {
			digits[n % 10] = true;
			n /= 10;
		}
	}
	return true;
}

void initArray() {
	for (int t = 0; t < 10; t++) {
		digits.push_back(false);
	}
}

void fillArray() {
	for (int t = 0; t < 10; t++) {
		digits[t] = false;
	}
}

void main()
{
	int n;
	int ans = 0;
	initArray();

	n = numInput();
	n = validateNumber(n);

	for (int t = 1; t <= n; t++) {
		if (checkNumber(t)) {
			ans++;
		}
		fillArray();
	}
	cout << ans << endl;
	system("pause");
}