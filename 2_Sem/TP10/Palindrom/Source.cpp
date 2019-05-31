#include <iostream>
extern "C" bool __fastcall  isPalindrome(int*, int);

using namespace std;

void main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int* ar = new int[n];
	cout << "Enter array" << endl;
	for (int t = 0; t < n; t++) {
		cin >> ar[t];
	}
	bool p = isPalindrome(ar, n);
	std::cout << "Array 'ar' is " << (p ? " " : "not ")<< "a palindrome"<< std::endl;
	system("pause");
}
