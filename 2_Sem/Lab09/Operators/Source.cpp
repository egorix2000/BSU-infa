#include <iostream>

using namespace std;

int subtract(const int a, const int b) {
	int result = 0;
	_asm {
		mov eax, a
		sub eax, b
		mov result, eax
	}
	return result;
}

int multiply(int a, int b) {
	int result = 0;
	_asm {
		mov eax, a
		imul b
		mov result, eax
	}
	return result;
}

int divide(int a, int b) {
	if (b == 0) {
		throw "Error!";
	}
	int result = 0;
	_asm {
		mov eax, a
		cdq
		idiv b
		mov result, eax
	}
	return result;
}

int mod(int a, int b) {
	int result = 0;
	_asm {
		mov eax, a
		cdq
		idiv b
		mov result, edx
	}
	return result;
}

int main() {
	int a = -2;
	int b = -5;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << a << " - " << b << " = " << subtract(a, b) << endl;
	cout << a << " * " << b << " = " << multiply(a, b) << endl;
	cout << a << " / " << b << " = " << divide(a, b) << endl;
	cout << a << " mod " << b << " = " << mod(a, b) << endl;

	system("pause");
	return 0;
}
