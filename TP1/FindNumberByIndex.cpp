/* Даны целое число k (1≤ k ≤180) и последовательность цифр 10111213...9899, в которой выписаны подряд все двузначные числа. Определить:
а)	номер пары цифр, в которую входит k-я цифра;
б)	двузначное число, образованное парой цифр, в которую входит k -я цифра;
в)	k -ю цифру, если известно, что:
		k — четное число;
		k — нечетное число.
Зам. Величины строкового типа не использовать


Egor Bychenok

input			output
-------------------------------
0               Error. Number must be >= 1 and <= 180

1               Index of pair: 1
                Two-digit number: 10
                Digit with index k: 1

50              Index of pair: 25
                Two-digit number: 34
                Digit with index k: 4

*/

#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double n;
	int pairNum;
	int twoDigitNumber;
	int digit;
	cout << "write number" << endl;
	cin >> n;
	if (n >= 1 && n <= 180){
        pairNum = ceil(n / 2);
        twoDigitNumber = pairNum/10 + 1;
        twoDigitNumber *= 10;
        twoDigitNumber += pairNum % 10 - 1;
        if ((int)n % 2 == 0){
            digit = twoDigitNumber%10;
        } else {
            digit = twoDigitNumber/10;
        }

        cout << "Index of pair: " << pairNum << endl;
        cout << "Two-digit number: " << twoDigitNumber << endl;
        cout << "Digit with index k: " << digit << endl;
	} else {
	    cout << "Error. Number must be >= 1 and <= 180" << endl;
	}
	system("pause");
}
