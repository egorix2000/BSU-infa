#include <iostream>
#include "ToString.h"

using namespace std;

int main() {
	int n = 17;
	double x = 6.75;
	cout << ToString("; ", 3.7, 25, n, x, "ad", 's') << endl;

	system("pause");

	return 0;
}
