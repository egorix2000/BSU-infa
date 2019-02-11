/*1.	Даны координаты поля шахматной доски x, y (целые числа, лежащие в диапазоне 1–8).
Учитывая, что левое нижнее поле доски (1, 1) является черным, проверить истинность
высказывания: «Данное поле является белым».


Egor Bychenok

input			output
-------------------------------
1 1				false
1 2				true
0 5				Error. x and y must be more than 0 and less than 9"


*/

#include <iostream>

using namespace std;


void main()
{
	int x, y;
	cout << "enter x and y" << endl;
	cin >> x >> y;
	if (x <= 8 && x >= 1 && y <= 8 && y >= 1) {
		if (x % 2 != y % 2) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	else {
		cout << "Error. x and y must be more than 0 and less than 9" << endl;
	}
	system("pause");
}