/*В первый день спортсмен пробежал x километров, а затем он каждый день увеличивал пробег на 10% 
от предыдущего значения. По данному числу y определите номер дня, на который пробег спортсмена 
составит не менее y километров. Например, при вводе 10 20 программа должна вывести 9. x и y – действительные числа, ответ – целое число.

Egor Bychenok

input			output
-------------------------------
10 20			9
1 0				1
5 5				1
11 60			19

*/

#include <iostream>

using namespace std;

void main()
{
	double x;
	double y;
	int ans = 1;
	cout << "write x (km) and y (km)" << endl;
	cin >> x >> y;
	while (x <= 0) {
		cout << "x must be more than 0. Write x" << endl;
		cin >> x;
	}
	while (x < y) {
		ans++;
		x *= 1.1;
	}
	cout << ans << endl;
	system("pause");
}