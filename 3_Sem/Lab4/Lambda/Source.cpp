#include <iostream>
#include <algorithm>
#include <list>
#include "funcsLambda.h"

using namespace std;

int main() {
	list<int> list {1, 3, 56, 14, 0, 7, -3, -29, 17, 1, 8, 6};

	cout << "List<int>:" << endl;
	outLambda(list);
	cout << endl;

	cout << "First even number in list: " << firtsEven(list) << endl;
	cout << "Amount of even numbers: " << sumEven(list) << endl;

	cout << "Sorted list:" << endl;
	sortLamda(list);
	outLambda(list);
	cout << endl;

	cout << "List witout negative numbers:" << endl;
	replaceNegatives(list);
	outLambda(list);
	cout << endl;

	system("pause");

	return 0;
}