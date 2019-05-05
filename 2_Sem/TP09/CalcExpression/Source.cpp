#include <iostream>
#include <excpt.h>
#include <windows.h>

using namespace std;

extern "C" int __stdcall calcExpressionInt(int, int);
extern "C" short __fastcall calcExpressionShort(short, short);

int main() {
	int a;
	int b;
	int resultInt = 0;
	int resultShort = 0;
	cout << "Enter numbers a and b" << endl;
	cin >> a >> b;

	__try {

		resultInt = calcExpressionInt(a, b);
		resultShort = calcExpressionShort(a, b);

		cout << "[Int] Value of expression is: " << resultInt << endl;
		cout << "[Short] Value of expression is: " << resultShort << endl;
	}
	__except (GetExceptionCode() == EXCEPTION_INT_DIVIDE_BY_ZERO ? 
		EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
		cout << "Exception: division by zero" << endl;
	}
	
	system("pause");
	return 0;
}