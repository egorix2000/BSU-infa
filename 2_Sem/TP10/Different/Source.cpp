#include <iostream>
extern "C" int __fastcall  uniqueElements(int*, int);
extern "C" int __fastcall  mostFrequentElement(int*, int);

using namespace std;

void main()
{
	// 15
	//1 4 2 4 3 3 3 0 3 5 4 4 1 5 4
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int * ar = new int[n];
	cout << "Enter array" << endl;
	for (int t = 0; t < n; t++) {
		cin >> ar[t];
	}
	int unique = uniqueElements(ar, n);
	std::cout << "Amount of unique elements: " << unique << std::endl;
	int mostFrequent = mostFrequentElement(ar, n);
	std::cout << "Most frequent element: " <<  mostFrequent << std::endl;
	system("pause");
}
