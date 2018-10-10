/**

Разработать приложение для сортировки целочисленного массива по возрастанию
 с помощью алгоритмов сортировки выбором, вставками, сортировки пузырьком,
 шейкерной сортировки,  четно-нечетной сортировки.

**/


#include <iostream>
#include <iomanip>
#include "getCPUTime.c"


using namespace std;

int compareNum;
int swapNum;
long double startTime;
long double endTime;

bool comparator(int a, int b){
    if (a > b){
        return true;
    } else {
        return false;
    }
}

int swapElements(int &a, int& b){
    swapNum++;
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int printResult(string sortType){
    cout << sortType << endl;
    cout << "time: " << endTime - startTime << endl;
	cout << "compareNum: " << compareNum << endl;
	cout << "swapNum: " << swapNum << endl;
	cout << endl;
	return 0;
}

int selectionSort(int a[], int n){
    startTime = getCPUTime( );
    swapNum = 0;
    compareNum = 0;
    int minIndex;

    for (int t = 0; t < n-1; t++){
        minIndex = t;
        for (int i = t+1; i < n; i++){
            compareNum++;
            if (comparator(a[minIndex], a[i])){
                minIndex = i;
            }
        }
        if (minIndex != t){
            swapElements(a[t], a[minIndex]);
        }
    }
    endTime = getCPUTime( );
    return 0;
}

int bubbleSort(int a[], int n){
    startTime = getCPUTime( );
    swapNum = 0;
    compareNum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            compareNum++;
            if (comparator(a[j], a[j + 1])) {
                swapElements(a[j], a[j+1]);
            }
        }
    }
    endTime = getCPUTime( );
    return 0;
}

int insertionSort(int a[], int n){
    startTime = getCPUTime( );
    swapNum = 0;
    compareNum = 0;
    int item;
    for (int t = 1; t < n; t++){
        item = t-1;
        while(item >= 0){
            compareNum++;
            if(comparator(a[item], a[item+1])){
                swapElements(a[item], a[item+1]);
            }
            item--;
        }
    }
    endTime = getCPUTime( );
    return 0;
}

int cocktailSort(int a[], int n){
    startTime = getCPUTime( );
    int lastSwap = 0;
    swapNum = 0;
    compareNum = 0;
    int left = 0;
    int right = n - 1;
    while(left <= right){
        lastSwap = -1;
        for (int i = left; i < right; i++){
            compareNum++;
            if (comparator(a[i], a[i+1])){
                lastSwap = i;
                swapElements(a[i], a[i+1]);
            }
        }

        if (lastSwap == -1){
            break;
        }

        right = lastSwap;
        lastSwap = -1;

        for (int i = right; i > left; i--){
            compareNum++;
            if (comparator(a[i-1], a[i])) {
                lastSwap = i;
                swapElements(a[i], a[i-1]);
            }
        }

        if (lastSwap == -1){
            break;
        }

        left = lastSwap;
    }
    endTime = getCPUTime( );
    return 0;
}

int oddEvenSort(int a[], int n){
    startTime = getCPUTime( );
    bool isSorted;
    swapNum = 0;
    compareNum = 0;
    for (int i = 0; i < n; i++) {
        isSorted = true;
		for (int j = 0; j < n - 1; j += 2) {
		    compareNum++;
			if (comparator(a[j], a[j + 1])) {
			    isSorted = false;
                swapElements(a[j], a[j+1]);
			}
		}

        for (int j = 1; j < n - 1; j += 2) {
		    compareNum++;
			if (comparator(a[j], a[j + 1])) {
			    isSorted = false;
                swapElements(a[j], a[j+1]);
			}
		}
        if (isSorted){
            break;
        }
	}
	endTime = getCPUTime( );
    return 0;
}

int copyArray(int *a, int n, int *aCopy){
     for (int t = 0; t < n; t++){
        aCopy[t] = a[t];
    }
    return 0;
}

int fillArrayDesc(int a[], int n){
    for (int t = 0; t < n; t++){
        a[t] = n-t;
    }
    return 0;
}

int fillArrayRandom(int a[], int n){
    for (int t = 0; t < n; t++){
        a[t] = rand()%1000;
    }
    return 0;
}

int fillArrayAsc(int a[], int n){
    for (int t = 0; t < n; t++){
        a[t] = t;
    }
    return 0;
}

int callAllSorts(int a[], int n, int aCopy[]){
    copyArray(a, n, aCopy);
    insertionSort(aCopy, n);
    printResult("insertionSort");

    copyArray(a, n, aCopy);
    selectionSort(aCopy, n);
    printResult("selectionSort");

    copyArray(a, n, aCopy);
    bubbleSort(aCopy, n);
    printResult("bubbleSort");

    copyArray(a, n, aCopy);
    cocktailSort(aCopy, n);
    printResult("cocktailSort");

    copyArray(a, n, aCopy);
    oddEvenSort(aCopy, n);
    printResult("oddEvenSort");
    return 0;
}

int main(){
    srand(time(NULL));
    int n = 10000;
    int *a = new int[n];
    int *aCopy = new int[n];
    cout << fixed << setprecision(6);

    fillArrayAsc(a, n);
    cout << "Asc" << endl;
    callAllSorts(a, n, aCopy);

    fillArrayRandom(a, n);
    cout << "Rand" << endl;
    callAllSorts(a, n, aCopy);

    fillArrayRandom(a, n);
    cout << "Rand" << endl;
    callAllSorts(a, n, aCopy);

    fillArrayRandom(a, n);
    cout << "Rand" << endl;
    callAllSorts(a, n, aCopy);

    fillArrayDesc(a, n);
    cout << "Desc" << endl;
    callAllSorts(a, n, aCopy);

    delete [] a;
    delete [] aCopy;

    return 0;
}
