/*Ќайти все натуральные числа, не превосход€щие заданного числа n, у которых все цифры в записи числа различны.

Egor Bychenok

input			output
-------------------------------
1               1
10              10
11				10
12              11
265				207
0				Number must be more than 0. Enter number

*/

#include <iostream>

using namespace std;

bool validateNumber(int n) {
	bool isValidate = true;
	if (n <= 0){
        isValidate = false;
	}
	return isValidate;
}

int numInput() {
	int n;
	cout << "Enter number" << endl;
	cin >> n;
	while (!validateNumber(n)){
        cout << "Number must be more than 0. Enter number" << endl;
        cin >> n;
	}
	return n;
}

bool checkNumber(bool digits[], int number){
	while (number > 0) {
		if (digits[number % 10]) {
			return false;
		} else {
			digits[number % 10] = true;
			number /= 10;
		}
	}
	return true;
}

void fillArray(bool digits[], int n, bool b) {
	for (int t = 0; t < n; t++) {
		digits[t] = b;
	}
}

int main()
{
	int n;
	int ans = 0;
	bool digits[10];

    fillArray(digits, 10, false);

	n = numInput();

	for (int t = 1; t <= n; t++) {
		if (checkNumber(digits, t)) {
			ans++;
		}
		fillArray(digits, 10, false);
	}
	cout << ans << endl;
	return 0;
}
