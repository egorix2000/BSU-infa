/**
Реализовать 3 функции каждая из которых принимает указатель
на массив и количество элементов и возвращает указатель
на новый массив. Первая функция ищет простые числа и
заносит их в новый массив, вторая – все числа кратные
трем, третья – все четные числа. Напишите функцию,
которая принимает указатель на функцию в качестве
параметра. Добавьте меню, в котором пользователь
может выбрать желаемую операцию.

input			            output
-----------------------------------------

11
1 2 3 4 5 6 7 8 9 10 11     2 3 5 7 11
1

10
1 2 3 4 5 6 7 8 9 10        2 4 6 8 10
2

10
1 2 3 4 5 6 7 8 9 10        3 6 9
3

**/


#include <iostream>
#include <cmath>
#include "OneDimensionalArrayLib.h"

using namespace std;

struct arrayWithLength{
    int* a;
    int n;
};

bool isSimple(int n){
    if (n == 1){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

arrayWithLength simpleNumbers (int* a, int n) {
    arrayWithLength ans;
    int *b;
    int m = 0;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (isSimple(a[i])){
            m++;
        }
    }
    b = new int[m];
    for (int i = 0; i < n; i++){
        if (isSimple(a[i])){
            b[k] = a[i];
            k++;
        }
    }
    ans.a = b;
    ans.n = m;
    return ans;
}

arrayWithLength evenNumbers (int* a, int n) {
    arrayWithLength ans;
    int *b;
    int m = 0;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            m++;
        }
    }
    b = new int[m];
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            b[k] = a[i];
            k++;
        }
    }
    ans.a = b;
    ans.n = m;
    return ans;
}

arrayWithLength modThreeNumbers (int* a, int n) {
    arrayWithLength ans;
    int *b;
    int m = 0;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (a[i] % 3 == 0){
            m++;
        }
    }
    b = new int[m];
    for (int i = 0; i < n; i++){
        if (a[i] % 3 == 0){
            b[k] = a[i];
            k++;
        }
    }
    ans.a = b;
    ans.n = m;
    return ans;
}

arrayWithLength getArray(int* a, int n, arrayWithLength (*func) (int*, int)){
    return func(a, n);
}

int main()
{
    int n;
    int* a;
    arrayWithLength (*func[3]) (int*, int) = {&simpleNumbers, &evenNumbers, &modThreeNumbers};
    arrayWithLength ansArray;
    int c;
    cout << "Enter length of array" << endl;
    cin >> n;
    a = new int[n];
    cout << "Enter array" << endl;
    enterArray(a, n);

    cout << "Enter one of operations: 1 to print simple numbers, 2 to print even, 3 to print mod 3 == 0" << endl;
    cout << "Print 0 to exit" << endl;
    cin >> c;
    while (c != 0){
        ansArray = getArray(a, n, func[c-1]);
        printArray(ansArray.a, ansArray.n);
        cout << "Enter length of array" << endl;
        cin >> n;
        a = new int[n];
        cout << "Enter array" << endl;
        enterArray(a, n);

        cout << "Enter one of operations: 1 to print simple numbers, 2 to print even, 3 to print mod 3 == 0" << endl;
        cout << "Print 0 to exit" << endl;
        cin >> c;
    }
    return 0;
}
