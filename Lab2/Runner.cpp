/*� ������ ���� ��������� �������� x ����������, � ����� �� ������ ���� ���������� ������ �� 10% 
�� ����������� ��������. �� ������� ����� y ���������� ����� ���, �� ������� ������ ���������� 
�������� �� ����� y ����������. ��������, ��� ����� 10 20 ��������� ������ ������� 9. x � y � �������������� �����, ����� � ����� �����.

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