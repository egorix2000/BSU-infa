/*Найти k-ую цифру в ряду цифр, составленных из подряд идущих натуральных чисел, начиная с 1: 12345678910111213…

Egor Bychenok

input			output
-------------------------------
1               1
4               4
19              4
561             3
0				number must be more than 0. Write number
*/


#include <iostream>
#include <cmath>

using namespace std;

int n;

void numInput() {
	cout << "Enter number" << endl;
	cin >> n;
}

void validateNumber() {
	while (n <= 0) {
		cout << "number must be more than 0. Write number" << endl;
		cin >> n;
	}
}

int findDigitsNumber(int n){
    int ans = 0;
    while (n > 0){
        n /= 10;
        ans++;
    }
    return ans;
}

void main()
{
	numInput();
	validateNumber();

    int counter = 1;
    while (n > 0){
        n -= findDigitsNumber(counter);
        counter++;
    }

    counter--;
    n += findDigitsNumber(counter);



    for (int t = 0; t < findDigitsNumber(counter)-n; t++){
        counter /= 10;
    }
    cout << counter % 10 << endl;
	system("pause");
}
