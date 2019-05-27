#include <iostream>

using namespace std;

extern "C" int __cdecl shift(int** matrix, int n, int m, int k);

int main() {
	int arraySize;
	int k;
	int n;
	int m;
	int** a;
	cout << "Enter size (n and m)" << endl;
	cin >> n >> m;
	a = new int* [n];
	cout << "Enter array" << endl;
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << "Enter k" << endl;
	cin >> k;
	_asm {
		mov edi, k
		mov eax, n
		mov ebx, m
		mul ebx
		mov arraySize, eax;

	begin_k_loop:

		dec edi
		cmp edi, 0
		jl end_k_loop
			
		mov esi, 4; индекс
		mov ecx, a
		mov ecx, [ecx]
		mov ecx, [ecx + esi * 4]
		mov ebx, ecx
		begin_loop :
			inc esi
			cmp esi, arraySize
			jge end_loop

			mov ecx, a
			mov ecx, [ecx]
			mov ecx, [ecx + esi * 4]

			mov edx, ecx

			mov ecx, a
			mov ecx, [ecx]

			mov [ecx + esi * 4], ebx
			mov ebx, edx

			jmp begin_loop
		end_loop:
		mov esi, 0
		mov ecx, a
		mov ecx, [ecx]
		mov [ecx + esi * 4], ebx
		jmp begin_k_loop
	end_k_loop:
}
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < m; i++) {
			cout << a[t][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
