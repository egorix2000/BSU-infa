/*Для заданного n найти все меньшие его совершенные числа (совершенным называется число, равное сумме всех своих делителей, не равных самому числу).

Egor Bychenok

input			output
-------------------------------
6               No numbers
7               6
10000           6 28 496 8128
0				number must be more than 0. Write number
*/


#include <iostream>
#include <cmath>

using namespace std;

long long n;

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

long long DividerSum(long long n){
    long long ans = 0;
    for (long long t = 1; t < n/2+1; t++){
        if(n % t == 0){
            ans += t;
        }
    }
    return ans;
}

void main()
{
    bool isExist = false;
	numInput();
	validateNumber();

    for (long long t = 2; t < n; t++){
        if (t == DividerSum(t)){
            cout << t << " ";
            isExist = true;
        }
    }
    if (!isExist){
        cout << "No numbers";
    }
    cout << endl;
	system("pause");
}
