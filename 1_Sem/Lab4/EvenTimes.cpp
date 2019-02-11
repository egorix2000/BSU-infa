/**

Дан массив целых чисел, в котором все числа кроме одного встречаются
четное количество раз, одно число встречается нечетное количество раз.
Найти это число.


input			            output
-----------------------------------
7
1 1 2 1 1 3 2               3

1
1                           1

3
1 1 2                       2

3
2 1 1                       2

**/


#include <iostream>
#include "MyLib.h"

using namespace std;


int main()
{
    int n;
    int ans;
    int *a;
    cout << "Enter array length" << endl;
    cin >> n;

    a = new int[n];
    cout << "Enter array elements" << endl;
    enterArray(a, n);

    ans = a[0];

    for (int t = 1; t < n; t++){
        ans ^= a[t];
    }

    cout << ans << endl;
    return 0;
}
