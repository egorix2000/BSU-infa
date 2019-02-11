/*
Известны площадь квадрата и площадь круга. Определить уместится ли квадрат в круге и уместится ли круг в квадрате

Egor Bychenok

input			output

-----------------------------------

1 1				Square can not be put into circle
				Circle can not be put into square

1 3.14			Square can be put into circle
				Circle can not be put into square

-1 2			square of square must be > 0
				write square of circle
**/

#include <iostream>
#include <math.h>

using namespace std;

const double SQRT_TWO = sqrt(2);
const double PI = 3.14;

void main()
{
	double squareOfSquare;
	double squareOfCircle;
	double diagonal;
	double diametr;
	double side;

	cout << "write square of square and square of circle" << endl;
	cin >> squareOfSquare >> squareOfCircle;

	while (squareOfSquare <= 0) {
		cout << "square of square must be > 0" << endl;
		cout << "write square of square" << endl;
		cin >> squareOfSquare;
	}

	while (squareOfCircle <= 0) {
		cout << "square of circle must be > 0" << endl;
		cout << "write square of circle" << endl;
		cin >> squareOfCircle;
	}

	diagonal = sqrt(squareOfSquare)*SQRT_TWO;
	diametr = sqrt(squareOfCircle / PI) * 2;
	side = sqrt(squareOfSquare);

	if (diagonal <= diametr) {
		cout << "Square can be put into circle" << endl;
	}
	else {
		cout << "Square can not be put into circle" << endl;
	}

	if (diametr <= side) {
		cout << "Circle can be put into square" << endl;
	}
	else {
		cout << "Circle can not be put into square" << endl;
	}

	system("pause");
}
