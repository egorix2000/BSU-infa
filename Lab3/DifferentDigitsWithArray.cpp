/*Найти количество различных цифр в записи заданного натурального числа. 

Egor Bychenok

input			output
-------------------------------
1				1
11				1
1544			3
0				number must be more than 0. Write number

*/

#include <iostream>
#include <vector>

using namespace std;

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

int findDifferentDigits(vector<bool> digits, int n){
	int ans = 0;
	while (n > 0) {
		digits[n % 10] = true;
		n /= 10;
	}
	for (int t = 0; t < 10; t++) {
		if (digits[t]) {
			ans++;
		}
	}
	return ans;
}

void main()
{
	int n;
	int ans;
	vector<bool> digits;
	for (int t = 0; t < 10; t++) {
		digits.push_back(false);
	}

	n = numInput();
	n = validateNumber(n);

	ans = findDifferentDigits(digits, n);
	cout << ans << endl;
	system("pause");
}