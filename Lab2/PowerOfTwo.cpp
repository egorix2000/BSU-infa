/*Дано натуральное число n. Определите, является ли оно степенью числа 2, и выведите слово YES, если является и слово NO, если не является

Egor Bychenok

input			output
-------------------------------
1024			YES
1				YES
3				NO
-2				number must be more than 0. Write number

*/

#include <iostream>

using namespace std;

void main()
{
    bool ifPower = true;
	int n;
	cout << "write number" << endl;
	cin >> n;
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			cout << "NO" << endl;
			ifPower = false;
			break;
		}
	}
	if (ifPower){
        cout << "YES" << endl;
	}
	system("pause");
}
