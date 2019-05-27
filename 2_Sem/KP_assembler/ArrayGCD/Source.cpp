#include <iostream>

using namespace std;

extern "C" int __fastcall  lcm(int*, int);

int main() {
	int n;
	int ans;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter array" << endl;
	int* ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	_asm {
		mov ecx, ar
		mov edx, n
		call lcm
		mov ans, eax
	}
	std::cout << "Lcm of all elements: " << ans << std::endl;
	return 0;
}