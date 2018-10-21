/*Для заданного n найти все меньшие его совершенные числа (совершенным называется число, равное сумме всех своих делителей, не равных самому числу).

Egor Bychenok

input			output
-------------------------------
6               No numbers
7               6
10000           6 28 496 8128
0				Number must be more than 0. Enter number
*/


#include <iostream>
#include <cmath>

using namespace std;

bool validateNumber(long long n) {
	bool isValidate = true;
	if (n <= 0){
        isValidate = false;
	}
	return isValidate;
}

int numInput() {
	long long n;
	cout << "Enter number" << endl;
	cin >> n;
	while (!validateNumber(n)){
        cout << "Number must be more than 0. Enter number" << endl;
        cin >> n;
	}
	return n;
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

int main()
{
    long long n;
    bool isExist = false;

	n = numInput();

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
	return 0;
}
