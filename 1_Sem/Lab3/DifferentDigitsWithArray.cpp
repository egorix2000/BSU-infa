/*Найти количество различных цифр в записи заданного натурального числа.

Egor Bychenok

input			output
-------------------------------
1				1
11				1
1544			3
15234           5
111332          3
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

int findDifferentDigits(bool digits[], int number){
	int ans = 0;
	while (number > 0) {
		digits[number % 10] = true;
		number /= 10;
	}
	for (int t = 0; t < 10; t++) {
		if (digits[t]) {
			ans++;
		}
	}
	return ans;
}

void fillArray(bool digits[], int n, bool b) {
	for (int t = 0; t < n; t++) {
		digits[t] = b;
	}
}

int main()
{
	int n;
	int ans;
	bool digits[10];

    fillArray(digits, 10, false);
	n = numInput();

	ans = findDifferentDigits(digits, n);
	cout << ans << endl;
	return 0;
}
