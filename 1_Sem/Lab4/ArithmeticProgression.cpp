/**

Добавить к некоторой последовательности  A=(ai), i=1..n, n<=100,
наименьшее  число элементов,  чтобы  получить  арифметическую
прогрессию (например, 22 1 36  -> 1  8 15 22 29 36).



input			            output
-----------------------------------
3
22 1 36                     1 8 15 22 29 36

4
1 1 1 1                     1 1 1 1

4
1 1 2 3                     Impossible to make arithmetic progression

5
9 18 27 7 0                 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27

4
9 18 27 0                   0 9 18 27
**/


#include <iostream>
#include "MyLib.h"


using namespace std;



int main()

{
    int n;
    bool ifEqualExist = false;
    bool ifDifferentExist = false;
    int d;
    int *a;
    cout << "Enter array length" << endl;
    cin >> n;

    a = new int[n];
    cout << "Enter array elements" << endl;
    enterArray(a, n);

    sortArray(a, n);

    if (n != 1){
        d = a[1]-a[0];
        for (int t = 1; t < n; t++){
            if (a[t] == a[t-1]){
                ifEqualExist = true;
            }
            if (a[t] != a[t-1]){
                ifDifferentExist = true;
            }
            d = gcd(d, a[t] - a[t-1]);
        }
        if (ifDifferentExist && ifEqualExist){
            cout << "Impossible to make arithmetic progression" << endl;
        } else if (ifEqualExist && !ifDifferentExist){
            coutArray(a, n);
        } else {
            while (a[0] <= a[n-1]){
                cout << a[0] << " ";
                a[0] += d;
            }
            cout << endl;
        }
    } else {
        coutArray(a, n);
    }
    return 0;

}
