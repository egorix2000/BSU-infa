/*Пользователь вводит четыре числа. Найдите наибольшее четное число среди них. Если оно не существует, выведите фразу "not found".

Egor Bychenok

input			output

-----------------------------------

1 4 2 3			4

1 1 1 1			notFound

-2 5 3 3		-2
*/

#include <iostream>

using namespace std;

void main()
{
	int current;
	int max = 0;
	bool ifFound = false;

	cout << "write four numbers" << endl;

	for (int t = 0; t < 4; t++) {
		cin >> current;
		if (current % 2 == 0 && (current > max || !ifFound)) {
			ifFound = true;
			max = current;
		}
	}

	if (ifFound) {
		cout << max << endl;
	}
	else {
		cout << "not found" << endl;
	}

	system("pause");
}
