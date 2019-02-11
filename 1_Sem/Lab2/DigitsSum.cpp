/*Дано натуральное число n. Выведите сумму цифр числа n. 

Egor Bychenok

input			output
-------------------------------
10				1
1345			13
0				number must be more than 0. Write number

*/

#include <iostream>

using namespace std;

void main()
{
	int n;
	int ans = 0;
	cout << "write number" << endl;
	cin >> n;
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	cout << ans << endl;
	system("pause");
}