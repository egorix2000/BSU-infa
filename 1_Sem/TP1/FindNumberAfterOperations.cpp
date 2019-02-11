/*�� ������������ ����� � ����� ��� ��������� �����. ����� ��������� ��������� �� 10,
� � �������� ����� ��������� ��������� ����� ����� x, �� ���������� ����� 237. ����� ����� �.

Egor Bychenok

input			output
----------------------------

237				372
-175			-751
0				Error! Number must contain 3 digits.

*/

#include <iostream>

using namespace std;

void main()
{
	int n;
	int firstNumber;
	bool minus = false;
	cin >> n;
	if (n < 0) {
		minus = true;
	}
	n = abs(n);
	if (n < 100 || n > 999) {
		cout << "Error! Number must contain 3 digits." << endl;
	}
	else {
		firstNumber = n / 100;
		n %= 100;
		n *= 10;
		n += firstNumber;
		if (minus) {
			cout << "-";
		}
		cout << n << endl;
	}
	system("pause");
}
