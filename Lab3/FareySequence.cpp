/*Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых меньше или равены n.

Egor Bychenok

input			output
-------------------------------
1				0/1 1/1
2				0/1 1/2 1/1
7               0/1 1/7 1/6 1/5 1/4 2/7 1/3 2/5 3/7 1/2 4/7 3/5 2/3 5/7 3/4 4/5 5/6 6/7 1/1
0				number must be more than 0. Write number
*/


#include <iostream>
#include <cmath>

using namespace std;

int n;

struct fraction
{
	double p;
	double q;
};

void numInput() {
	cout << "Enter number" << endl;
	cin >> n;
}

void validateNumber() {
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
}

fraction nextFraction(fraction prew, fraction current) {
	fraction next;
	int k = floor((n + prew.q) / current.q);
	next.p = k * current.p - prew.p;
	next.q = k * current.q - prew.q;
	return next;
}


void main()
{
	fraction prew;
	fraction current;
	fraction temp;

	numInput();
	validateNumber();

	prew.p = 0;
	prew.q = 1;
	current.p = 1;
	current.q = n;

	cout << prew.p << "/" << prew.q << " ";
	cout << current.p << "/" << current.q << " ";

	while (current.q != 1 || current.p != 1) {
		temp = prew;
		prew = current;
		current = nextFraction(temp, prew);
		cout << current.p << "/" << current.q << " ";
	}
	cout << endl;
	system("pause");
}
