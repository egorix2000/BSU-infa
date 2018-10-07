#include <iostream>

using namespace std;

void enterArray(int *a, int n){
    for (int t = 0; t < n; t++){
        cin >> a[t];
    }
}

void coutArray(int *a, int n){
    for (int t = 0; t < n; t++){
        cout << a[t] << " ";
    }
    cout << endl;
}

void coutArrayInReverseOrder(int *a, int n){
    for (int t = n-1; t >= 0; t--){
        cout << a[t] << " ";
    }
    cout << endl;
}

void swapElements(int &a, int& b){
    int *temp = new int;
    *temp = a;
    a = b;
    b = *temp;
    delete temp;
}

bool comparator(int a, int b){
    if (a > b){
        return true;
    } else {
        return false;
    }
}

void sortArray(int *a, int n, bool (*comparator)(int, int)){
    int minIndex;

    for (int t = 0; t < n-1; t++){
        minIndex = t;
        for (int i = t+1; i < n; i++){
            if (comparator(a[minIndex], a[i])){
                minIndex = i;
            }
        }
        if (minIndex != t){
            swapElements(a[t], a[minIndex]);
        }
    }
}

void fillArrayWithZeros(int *a, int n){
    for (int t = 0; t < n; t++){
        a[t] = 0;
    }
}

void reverseArray(int *a, int n){
    for (int t = 0; t < n/2; t++){
        swapElements(a[t], a[n-t-1]);
    }
}

int gcd(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}
