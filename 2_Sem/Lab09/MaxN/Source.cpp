#include <iostream>

using namespace std;

int main() {
	unsigned int a;
	unsigned int n = 0;
	unsigned int res;
	cout << "Enter a > 0" << endl;
	cin >> a;

	_asm {
		mov eax, a
		whileCorrect :
		mov res, eax
			inc n
			mul a
			jnc whileCorrect
	}

	cout << "Max n = " << n << "\n";

	system("pause");
	return 0;
}