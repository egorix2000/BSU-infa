/**

Найти сумму и произведение двух многочленов, заданных массивами своих коэффициентов.


input			            output
-----------------------------------------
3 1                         3 2 7 9
3 2 5 8                     6 7 12 21 8
2 1

1 3                         3 2 7 9
2 1                         6 7 12 21 8
3 2 5 8

2 2                         2 5 3
1 4 2                       1 5 7 6 2
1 1 1

4 3                         1 7 0 4 5
1 5 0 0 3                   2 10 4 22 16 0 12 6
2 0 4 2
**/


#include <iostream>
#include "MyLib.h"

using namespace std;


int main()
{
    int n;
    int m;
    int length;
    int multLength;
    int *temp;
    int *firstPolynom;
    int *secondPolynom;
    int *mult;
    int *sum;

    cout << "Enter power of of the first polynomial" << endl;
    cin >> n;
    cout << "Enter power of of the second polynomial" << endl;
    cin >> m;
    multLength = m+n+1;
    n++;
    m++;

    if (m > n){
        length = m;
    } else {
        length = n;
    }

    firstPolynom = new int[length];
    secondPolynom = new int[length];
    fillArrayWithZeros(firstPolynom, length);
    fillArrayWithZeros(secondPolynom, length);
    cout << "Enter coefficients of the first polynomial" << endl;
    enterArray(firstPolynom, n);
    cout << "Enter coefficients of the second polynomial" << endl;
    enterArray(secondPolynom, m);

    if (m > n){
        swapElements(m, n);
        temp = firstPolynom;
        firstPolynom = secondPolynom;
        secondPolynom = temp;
    }

    sum = new int[n];
    mult = new int[multLength];
    fillArrayWithZeros(mult, multLength);
    fillArrayWithZeros(sum, multLength);
    coutArray(firstPolynom, n);
    coutArray(secondPolynom, n);

    for (int t = 0; t < n; t++){
        sum[t] += firstPolynom[t];
    }
    for (int t = 0; t < m; t++){
        sum[t+n-m] += secondPolynom[t];
    }

    reverseArray(firstPolynom, n);
    reverseArray(secondPolynom, n);

    for (int t = 0; t < n; t++){
        for (int i = 0; i < m; i++){
            mult[t+i] += firstPolynom[t]*secondPolynom[i+n-m];
        }
    }

    cout << "Sum: " << endl;
    coutArray(sum, length);
    cout << "Multiplication: " << endl;
    coutArrayInReverseOrder(mult, multLength);
    return 0;
}
