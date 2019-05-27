#include <iostream>

using namespace std;

extern "C" int __cdecl shift(int** matrix, int n, int m, int k);

int main() {
	int arraySize;
	int n = 3;
	int m = 4;
	int a[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	int k = 3;
	_asm {
		mov ecx, a
		mov edi, k
		mov eax, n
		mov ebx, m
		mul ebx
		mov arraySize, eax;

	begin_k_loop:

		dec edi
		cmp edi, 0
		jl end_k_loop
			
		xor esi, esi; ??????
		mov ebx, a[esi * 4]
		begin_loop :
			inc esi
			cmp esi, arraySize
			jge end_loop
			mov edx, a[esi * 4]
			mov a[esi * 4], ebx
			mov ebx, edx

			jmp begin_loop
		end_loop:
		mov a[0], ebx
		jmp begin_k_loop
	end_k_loop:
}
	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < 4; i++) {
			cout << a[t][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
