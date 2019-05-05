#include <iostream>

extern "C" int solveEquation(int, int, bool&, bool&);

using namespace std;

int main() {
	int a;
	int b;
	int solution;
	bool hasSolutions = true;
	bool doesInfiniteNumberOfSolutions = false;
	cout << "Enter numbers a and b" << endl;
	cin >> a >> b;

	solution = solveEquation(a, b, hasSolutions, doesInfiniteNumberOfSolutions);
	if (doesInfiniteNumberOfSolutions) {
		cout << "x = any number" << endl;
	}
	else if (hasSolutions) {
		cout << "Solution for equation " << a << "x + " << b << " = 0:" <<
			solution << endl;
	}
	else {
		cout << "No solutions" << endl;
	}
	system("pause");
	return 0;
}