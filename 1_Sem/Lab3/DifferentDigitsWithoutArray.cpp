/*Найти количество различных цифр в записи заданного натурального числа n (разработать алгоритмы с использованием и без использования массивов).

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

int differentDigits(int n) {
	int copyN;
	int ans = 0;
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

int main()
{
    int n;
    int ans;

	n = numInput();
    ans = differentDigits(n);

	cout << ans << endl;
	return 0;
}
