/* ƒано квадратное уравнение. Ќайти корни, в противном случае вывести соответствующее сообщение.

Egor Bychenok

input			output

-----------------------------------
0 0 0           	roots: all numbers

0 0 1           	no roots

1 2 1			root: -1

1 5 6			roots: -2 -3

1 1 1			no roots

0 2 1			root: -0.5
*/

#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double a, b, c;
	double x1, x2;
	double discriminant;

	cout << "write coefficient of quadratic equation" << endl;
	cin >> a >> b >> c;

	if (a == 0) {
        if (b == 0){
            if (c == 0){
                cout << "roots: all numbers" << endl;
            } else {
                cout << "no roots" << endl;
            }
        } else {
            x1 = (-1)*c/b;
            cout << "root: " << x1 << endl;
        }
	}

	else {
        discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            cout << "no roots" << endl;
        } else {
            x1 = (b * (-1) + sqrt(discriminant)) / (2.0 * a);
            x2 = (b * (-1) - sqrt(discriminant)) / (2.0 * a);

            if (x1 == x2) {
                cout << "root: " << x1 << endl;
            }
            else {
                cout << "roots: " << x1 << " and " << x2 << endl;
            }
        }
	}
	system("pause");
}
