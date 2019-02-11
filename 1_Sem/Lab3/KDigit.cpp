/*Найти k-ую цифру в ряду цифр, составленных из подряд идущих натуральных чисел, начиная с 1: 12345678910111213…

Egor Bychenok

input			output
-------------------------------
1               1
4               4
19              4
20              1
21              5
561             3
0				Number must be more than 0. Enter number
*/


#include <iostream>

using namespace std;

bool validateNumber(int n) {
	bool isValidate = true;
	if (n <= 0){
        isValidate = false;
	}
	return isValidate;
}

int numInput() {
	int n;
	cout << "Enter number" << endl;
	cin >> n;
	while (!validateNumber(n)){
        cout << "Number must be more than 0. Enter number" << endl;
        cin >> n;
	}
	return n;
}

int findNumberOfDigitsInNumber(int n){
    int ans = 0;
    while (n > 0){
        n /= 10;
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    int counter;

    n = numInput();

    counter = 1;
    while (n > 0){
        n -= findNumberOfDigitsInNumber(counter);
        counter++;
    }

    counter--;
    n += findNumberOfDigitsInNumber(counter);

    for (int t = 0; t < findNumberOfDigitsInNumber(counter)-n; t++){
        counter /= 10;
    }
    cout << counter % 10 << endl;
	return 0;
}
