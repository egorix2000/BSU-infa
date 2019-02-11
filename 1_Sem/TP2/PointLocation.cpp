/*1.	Задана точка M с координатами (x,y). Определить месторасположение
этой точки в декартовой системе координат (является ли эта точка началом
координат, лежит на одной из координатных осей или расположена в одном из
координатных углов).


Egor Bychenok

input				output
--------------------------------------------
0 0					Point is the origin of coordinates
0 5					Point lies on he coordinate axis Oy
5.1 0				Point lies on he coordinate axis Ox
5 4.7				Point lies in the first coordinate angle
-4 1				Point lies in the second coordinate angle
1 -4				Point lies in the fourth coordinate angle
-0.001 -0.1			Point lies in the third coordinate angle
*/

#include <iostream>

using namespace std;


void main()
{
	double x, y;
	cout << "enter x and y" << endl;
	cin >> x >> y;
	if (x == 0) {
		if (y == 0) {
			cout << "Point is the origin of coordinates" << endl;
		}
		else {
			cout << "Point lies on he coordinate axis Oy" << endl;
		}
	}
	else if (y == 0) {
		cout << "Point lies on he coordinate axis Ox" << endl;
	}
	else {
		if (x > 0) {
			if (y > 0) {
				cout << "Point lies in the first coordinate angle" << endl;
			}
			else {
				cout << "Point lies in the fourth coordinate angle" << endl;
			}
		}
		if (x < 0) {
			if (y > 0) {
				cout << "Point lies in the second coordinate angle" << endl;
			}
			else {
				cout << "Point lies in the third coordinate angle" << endl;
			}
		}
	}
	system("pause");
}