#include <iostream>
#include <windows.h>

using namespace std;

extern "C" int Swap(WORD&, WORD&);

int main() {
	WORD a;
	WORD b;
	cout << "Enter numbers a and b" << endl;
	cin >> a >> b;

	while (a < 0 || b < 0) {
		cout << "Error. mbers must be more or equal to 0. Enter numbers a and b" << endl;
		cin >> a >> b;
	}

	Swap(a, b);

	cout << "Swap occurred" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	system("pause");
	return 0;
}