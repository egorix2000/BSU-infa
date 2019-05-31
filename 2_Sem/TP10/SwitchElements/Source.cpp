#include <iostream>
#include <iomanip>
extern "C" void __cdecl  swap(int** matrix, int n, int i);
extern "C" void __fastcall  switchColumnExtrema(int** matrix, int n);

using namespace std;

void main()
{
	int n;
	std::cout << "Enter n:" << endl;
	std::cin >> n;
	int** matrix = new int*[n];
	std::cout << "Enter matrix:" << endl;
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
	int index;
	std::cout << "Enter i:" << endl;;
	std::cin >> index;
	index--;

	swap(matrix, n, index);

	std::cout << "Matrix after swap: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << endl;
	}
	switchColumnExtrema(matrix, n);
	std::cout << "Matrix after switching column:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << endl;
	}
	system("pause");
}
