#include <iostream>

using namespace std;

unsigned int calculate(unsigned int a) {
	int result = 0;

	_asm {
		mov ebx, 1 // full expression
		mov eax, a

		mul eax // a^2
		add ebx, eax // a^2 + 1

		mul eax // a^4
		add ebx, eax // a^4 + a^2 + 1

		mov eax, ebx
		mul a
		mov result, eax
	}
	return result;
}

int main() {
	unsigned int a;

	cout << "Enter a (a > 0)" << endl;
	cin >> a;

	cout << "a^5 + a^3 + a = " << calculate(a) << endl;

	system("pause");

	return 0;
}