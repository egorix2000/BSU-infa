/*1.	���� ����� ����� � ��������� �� 100 �� 999. ������� ������ ���������� �������� �������
�����, ��������: 256 � "������ ��������� �����", 814 � "��������� ������������".


Egor Bychenok

input				output
--------------------------------------------
256					������ ��������� �����
814					��������� ������������
100					���
210					������ ������
0					Error. number of month must be more than 99 and less than 1000
*/

#include <iostream>
#include <Windows.h>

using namespace std;


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	bool secondOne = false;
	int firstDigit;
	int secondDigit;
	int thirdDigit;
	cout << "������� �����" << endl;
	cin >> n;
	if (n >= 100 && n <= 999) {
		thirdDigit = n % 10;
		n /= 10;
		secondDigit = n % 10;
		n /= 10;
		firstDigit = n;

		switch (firstDigit)
		{
		case 1:
		{
			cout << "���" << " ";
			break;
		}
		case 2:
		{
			cout << "������" << " ";
			break;
		}
		case 3:
		{
			cout << "������" << " ";
			break;
		}
		case 4:
		{
			cout << "���������" << " ";
			break;
		}
		case 5:
		{
			cout << "�������" << " ";
			break;
		}
		case 6:
		{
			cout << "��������" << " ";
			break;
		}
		case 7:
		{
			cout << "�������" << " ";
			break;
		}
		case 8:
		{
			cout << "���������" << " ";
			break;
		}
		case 9:
		{
			cout << "���������" << " ";
			break;
		}
		default:
			break;
		}

		switch (secondDigit)
		{
		case 1:
		{
			secondOne = true;
			break;
		}
		case 2:
		{
			cout << "��������" << " ";
			break;
		}
		case 3:
		{
			cout << "��������" << " ";
			break;
		}
		case 4:
		{
			cout << "�����" << " ";
			break;
		}
		case 5:
		{
			cout << "���������" << " ";
			break;
		}
		case 6:
		{
			cout << "����������" << " ";
			break;
		}
		case 7:
		{
			cout << "���������" << " ";
			break;
		}
		case 8:
		{
			cout << "�����������" << " ";
			break;
		}
		case 9:
		{
			cout << "���������" << " ";
			break;
		}
		default:
			break;
		}

		switch (thirdDigit)
		{
		case 0:
		{
			if (secondOne) {
				cout << "������";
			}
			cout << endl;
			break;
		}
		case 1:
		{
			if (secondOne) {
				cout << "�����������" << endl;
			}
			else {
				cout << "����" << endl;
			}
			break;
		}
		case 2:
		{
			if (secondOne) {
				cout << "����������" << endl;
			}
			else {
				cout << "���" << endl;
			}
			break;
		}
		case 3:
		{
			if (secondOne) {
				cout << "����������" << endl;
			}
			else {
				cout << "���" << endl;
			}
			break;
		}
		case 4:
		{
			if (secondOne) {
				cout << "������������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			break;
		}
		case 5:
		{
			if (secondOne) {
				cout << "����������" << endl;
			}
			else {
				cout << "����" << endl;
			}
			break;
		}
		case 6:
		{
			if (secondOne) {
				cout << "�����������" << endl;
			}
			else {
				cout << "�����" << endl;
			}
			break;
		}
		case 7:
		{
			if (secondOne) {
				cout << "����������" << endl;
			}
			else {
				cout << "����" << endl;
			}
			break;
		}
		case 8:
		{
			if (secondOne) {
				cout << "������������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			break;
		}
		case 9:
		{
			if (secondOne) {
				cout << "������������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			break;
		}
		default:
			break;
		}
	}
	else {
		cout << "Error. number of month must be more than 99 and less than 1000" << endl;
	}
	system("pause");
}