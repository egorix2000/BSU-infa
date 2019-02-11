/*1. ƒан номер мес€ца (1 Ц €нварь, 2 Ц февраль, Е). ¬ывести название соответствующего времени года (Ђзимаї, Ђвеснаї и т.д.).


Egor Bychenok

input				output
--------------------------------------------
2					winter
5					spring
9					autumn
7					summer
0					Error. number of month must be more than 0 and less than 13
*/

#include <iostream>

using namespace std;


void main()
{
	int month;
	cout << "enter number of month" << endl;
	cin >> month;
	if (month >= 1 && month <= 12) {
		switch (month) {
		case 12:
		case 1:
		case 2:
		{
			cout << "winter" << endl;
			break;
		}
		case 3:
		case 4:
		case 5:
		{
			cout << "spring" << endl;
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			cout << "summer" << endl;
			break;
		}
		case 9:
		case 10:
		case 11:
		{
			cout << "autumn" << endl;
			break;
		}
		default:
			break;
		}
	}
	else {
		cout << "Error. number of month must be more than 0 and less than 13" << endl;
	}
	system("pause");
}