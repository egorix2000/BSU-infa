/**

Протестировать работу на массиве комплексных чисел, найдя наибольшее/наименьшее
по длине вектора комплексное число,  а также поместив элементы массива в
стек и очередь и удалив элементы из этих структур данных.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"
#include "ComplexNumber.h"
#include "ComplexNumberOperators.h"
#include "ComplexNumberStack.h"
#include "ComplexNumberQueue.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/input1.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/output1.txt";

void stackTest(ComplexNumberStack stack){
    ComplexNumber* cn1 = new ComplexNumber(1, 1);
    ComplexNumber* cn2 = new ComplexNumber(2, 2);
    ComplexNumber* copyCn2 = new ComplexNumber(*cn2); // 2 2 created
    ComplexNumber* cn3 = new ComplexNumber(3, 3);

    stack.pop(); // nothing happened cause no elements in stack
    stack.push(*cn1);
    cout << "push 1, top real:" << stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.push(*cn2);
    cout << "push 2, top real:" << stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.pop();
    cout  << "pop, top real:"<< stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.push(*copyCn2);
    cout  << "push 2, top real:"<< stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.push(*cn3);
    cout << "push 3, top real:" << stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.pop();
    cout << "pop, top real:" << stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.pop();
    cout << "pop, top real:" << stack.getTop().real << " size:" << stack.getSize() << endl;
    stack.pop();
    cout << "pop, is empty:" << stack.isEmpty() << " size:" << stack.getSize() << endl;
}

void queueTest(ComplexNumberQueue queue){
    ComplexNumber* cn1 = new ComplexNumber(1, 1);
    ComplexNumber* cn2 = new ComplexNumber(2, 2);
    ComplexNumber* copyCn2 = new ComplexNumber(*cn2); // 2 2 created
    ComplexNumber* cn3 = new ComplexNumber(3, 3);

    queue.pop_front(); // nothing happened cause no elements in stack
    queue.push_back(*cn1);
    cout << "push_back 1, front real:" << queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.push_back(*cn2);
    cout << "push_back 2, front real:" << queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.pop_front();
    cout  << "pop_front, top real:"<< queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.push_back(*copyCn2);
    cout  << "push_back 2, front real:"<< queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.push_back(*cn3);
    cout << "push_back 3, front real:" << queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.pop_front();
    cout << "pop_front, front real:" << queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.pop_front();
    cout << "pop_front, front real:" << queue.getFront().real << " back real:" << queue.getBack().real << " size:" << queue.getSize() << endl;
    queue.pop_front();
    cout << "pop_front, is empty:" << queue.isEmpty() << " size:" << queue.getSize() << endl;
}

int findMaxIndex(ComplexNumber** a, int n){
    int maxIndex = 0;
    ComplexNumber maxNumber = *a[0];
    for (int i = 1; i < n; i++){
        if (ComplexNumberOperators::cmp(*a[i], maxNumber) > 0){
            maxIndex = i;
            maxNumber = *a[i];
        }
    }
    return maxIndex;
}

int findMinIndex(ComplexNumber** a, int n){
    int minIndex = 0;
    ComplexNumber minNumber = *a[0];
    for (int i = 1; i < n; i++){
        if (ComplexNumberOperators::cmp(*a[i], minNumber) < 0){
            minIndex = i;
            minNumber = *a[i];
        }
    }
    return minIndex;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    ComplexNumberStack myStack;
    ComplexNumberQueue myQueue;
    ComplexNumber* cn;
    ComplexNumber** numbers;
    int n;
    int k;
    int iMin;
    int iMax;
    double real;
    double imaginary;

    //stack test
    cout << "stack" << endl;
    stackTest(myStack);

    //queue test
    cout << "queue" << endl;
    queueTest(myQueue);

    //array test
    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        fin >> n;
        numbers = new ComplexNumber*[n];

        //read array
        k = 0;
        while (fin >> real >> imaginary){
            cn = new ComplexNumber(real, imaginary);
            numbers[k] = cn;
            k++;
        }

        iMax = findMaxIndex(numbers, n);
        iMin = findMinIndex(numbers, n);

        fout << "Index of max: " << iMax << endl;
        fout << "Index of min: " << iMin << endl;
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
