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

void swapElements(int &a, int& b){
    int *temp = new int;
    *temp = a;
    a = b;
    b = *temp;
    delete temp;
}

void swapPointers(int *a, int *b){
    int *temp = a;
    a = b;
    b = temp;
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

