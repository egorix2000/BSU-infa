/*1.	Дано целое число в диапазоне от 100 до 999. Вывести строку —словесное описание данного
числа, например: 256 — "двести пятьдесят шесть", 814 — "восемьсот четырнадцать".


Egor Bychenok

input				output
--------------------------------------------
256					двести пятьдесят шесть
814					восемьсот четырнадцать
100					сто
210					двести десять
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
	cout << "введите число" << endl;
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
			cout << "сто" << " ";
			break;
		}
		case 2:
		{
			cout << "двести" << " ";
			break;
		}
		case 3:
		{
			cout << "триста" << " ";
			break;
		}
		case 4:
		{
			cout << "четыреста" << " ";
			break;
		}
		case 5:
		{
			cout << "пятьсот" << " ";
			break;
		}
		case 6:
		{
			cout << "шестьсот" << " ";
			break;
		}
		case 7:
		{
			cout << "семьсот" << " ";
			break;
		}
		case 8:
		{
			cout << "восемьсот" << " ";
			break;
		}
		case 9:
		{
			cout << "девятьсот" << " ";
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
			cout << "двадцать" << " ";
			break;
		}
		case 3:
		{
			cout << "тридцать" << " ";
			break;
		}
		case 4:
		{
			cout << "сорок" << " ";
			break;
		}
		case 5:
		{
			cout << "пятьдесят" << " ";
			break;
		}
		case 6:
		{
			cout << "шестьдесят" << " ";
			break;
		}
		case 7:
		{
			cout << "семьдесят" << " ";
			break;
		}
		case 8:
		{
			cout << "восемьдесят" << " ";
			break;
		}
		case 9:
		{
			cout << "девяносто" << " ";
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
				cout << "десять";
			}
			cout << endl;
			break;
		}
		case 1:
		{
			if (secondOne) {
				cout << "одиннадтать" << endl;
			}
			else {
				cout << "один" << endl;
			}
			break;
		}
		case 2:
		{
			if (secondOne) {
				cout << "двенадцать" << endl;
			}
			else {
				cout << "два" << endl;
			}
			break;
		}
		case 3:
		{
			if (secondOne) {
				cout << "тринадцать" << endl;
			}
			else {
				cout << "три" << endl;
			}
			break;
		}
		case 4:
		{
			if (secondOne) {
				cout << "четырнадцать" << endl;
			}
			else {
				cout << "четыре" << endl;
			}
			break;
		}
		case 5:
		{
			if (secondOne) {
				cout << "пятнадцать" << endl;
			}
			else {
				cout << "пять" << endl;
			}
			break;
		}
		case 6:
		{
			if (secondOne) {
				cout << "шестнадцать" << endl;
			}
			else {
				cout << "шесть" << endl;
			}
			break;
		}
		case 7:
		{
			if (secondOne) {
				cout << "семнадцать" << endl;
			}
			else {
				cout << "семь" << endl;
			}
			break;
		}
		case 8:
		{
			if (secondOne) {
				cout << "восемнадцать" << endl;
			}
			else {
				cout << "восемь" << endl;
			}
			break;
		}
		case 9:
		{
			if (secondOne) {
				cout << "девятнадцать" << endl;
			}
			else {
				cout << "девять" << endl;
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