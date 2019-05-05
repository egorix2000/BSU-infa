#include <iostream>

using namespace std;

unsigned int getRemainder(unsigned int y) {
	unsigned int result;
	_asm {
		mov eax, y
		mov ecx, 3
		cdq
		mul ecx // eax = 3y
		mov ebx, 50
		sub ebx, eax // 50 - 3y
		mov eax, ebx
		mov ecx, 2
		div ecx // eax = (50 - 3y) / 2
		mov result, edx // remainder
	}
	return result;
}

unsigned int getXbyY(unsigned int y) {
	unsigned int result;
	_asm {
		mov eax, y
		mov ecx, 3
		mul ecx // 3y
		mov ebx, 50
		sub ebx, eax // 50 - 3y
		mov eax, ebx
		mov ecx, 2
		div ecx // (50 - 3y) / 2
		mov result, eax
	}
	return result;

}

int main() {
	unsigned int x;
	unsigned int y;

	unsigned int remainder;

	int yMax = int(50 / 3);

	cout << "Solutions to 2x + 3y = 50 :" << endl;
	for (y = 1; y <= yMax; ++y) {
		remainder = getRemainder(y);
		if (remainder == 0) {
			x = getXbyY(y);
			cout << "x = " << x << ", " << "y = " << y << endl;
		}
	}
	system("pause");
	return 0;
}