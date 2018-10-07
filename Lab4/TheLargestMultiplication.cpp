/**

Дан массив целых чисел, из этой последовательности целых чисел
выбрать три числа, произведение которых максимально


input			            output
-------------------------------------------------
3
1 2 -3				        -6

4
-3 4 0 1			        0

6
1 -5 -3 2 3 4			    60

6
-1 -2 -7 -1 -4 -3		    -2

2				            Error. Length must be more than 2.

**/


#include <iostream>
#include "MyLib.h"

using namespace std;


int main()
{
    int n;
    bool ifZeroExist = false;
    int ans;
    int nextMult;
    int *a;
    cout << "Enter array length" << endl;
    cin >> n;
    while (n < 3){
        cout << "Error. Length must be more than 2. Enter array length" << endl;
        cin >> n;
    }

    a = new int[n];
    cout << "Enter array elements" << endl;
    enterArray(a, n);

    sortArray(a, n);

    for (int t = 0; t < n; t++){
        if (a[t] == 0){
            ifZeroExist = true;
            break;
        }
    }

    ans = a[n-1]*a[n-2]*a[n-3];

    nextMult = a[n-1]*a[n-2]*a[0];
    if (nextMult > ans){
        ans = nextMult;
    }

    nextMult = a[n-1]*a[1]*a[0];
    if (nextMult > ans){
        ans = nextMult;
    }

    nextMult = a[2]*a[1]*a[0];
    if (nextMult > ans){
        ans = nextMult;
    }

    if (ans < 0 && ifZeroExist){
        ans = 0;
    }

    cout << ans;
    return 0;
}
