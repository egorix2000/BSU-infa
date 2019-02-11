#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void enterArray(int *a, int n){
    for (int t = 0; t < n; t++){
        cin >> a[t];
    }
}

void readArrayFromFile(int *a, int n, ifstream& fin){
    for (int t = 0; t < n; t++){
        fin >> a[t];
    }
}

void printArray(int *a, int n){
    for (int t = 0; t < n; t++){
        cout << a[t] << " ";
    }
    cout << endl;
}

void fillArrayRandom(int *a, int n){
    srand(time(NULL));
    for (int t = 0; t < n; t++){
        a[t] = rand()%100-50;
    }
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

int binarySearch(int *a, int n, int x){
    int left = 0;
    int right = n-1;
    int mid;
    while (right > left){
        mid = left + (right - left) / 2;
        if (x < a[mid]){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if (a[left] <= x){
        left++;
    }
    return left;
}


void insertSortArrayWithBinarySearch(int *a, int n){
    int pos;
    int current;
    for (int t = 1; t < n; t++){
        pos = binarySearch(a, t, a[t]);
        current = a[t];
        for (int i = t; i > pos; i--){
            a[i] = a[i-1];
        }
        a[pos] = current;
    }
}
