/*По данному натуральному числу n найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/n!.
Количество действий должно быть пропорционально n. Напишите программу, которая 
считывает значение n и выводит результат в виде действительного числа. 
К чему будет стремиться эта сумма при росте числа n?

Egor Bychenok

input			output
-------------------------------
1				2
2				2.5
15				2.71828
0				number must be more than 0. Write number

Стремится к e
*/

#include <iostream>

using namespace std;

void main()
{
	int n;
	double ans = 1;
	double fact = 1;
	cout << "write number" << endl;
	cin >> n;
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
	for (int t = 1; t <= n; t++) {
		ans += 1.0 / fact;
		fact *= t + 1;
	}
	cout << ans << endl;
	system("pause");
}