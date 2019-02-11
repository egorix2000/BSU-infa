/**

Составить описание класса для определения одномерных массивов целых чисел (векторов).
Предусмотреть возможность обращения к отдельному элементу массива с контролем выхода
за пределы массива, возможность задания произвольных границ индексов при создании
объекта, возможность выполнения операций поэлементного сложения и вычитания
массивов с одинаковыми границами индексов, умножения и деления всех
элементов массива на скаляр, вывода на экран элемента массива по
заданному индексу, вывода на экран всего массива. Написать
программу, демонстрирующую работу с этим классом.
Программа должна содержать меню, позволяющее
осуществить проверку всех методов класса.

**/

#include <iostream>
#include <cctype>
#include <cstring>

#include "Vector.h"

using namespace std;

void displayMenu(){
    cout << "Enter:" << endl;
    cout << "0 to exit" << endl;
    cout << "1 to enter array A" << endl;
    cout << "2 to enter array B" << endl;
    cout << "3 to display A" << endl;
    cout << "4 to display B" << endl;
    cout << "5 to add B to A" << endl;
    cout << "6 to add A to B" << endl;
    cout << "7 to subtract B from A" << endl;
    cout << "8 to subtract A from B" << endl;
    cout << "9 to multiply A with number" << endl;
    cout << "10 to multiply B with number" << endl;
    cout << "11 to divide A with number" << endl;
    cout << "12 to divide B with number" << endl;
    cout << "13 to print element of A" << endl;
    cout << "14 to print element of B" << endl;
}

void enter(Vector<int>& vector){
    int size;
    int element;
    cout << "enter size: ";
    cin >> size;
    vector.resize(size);
    cout << "enter array: ";
    for (int i = 0; i < size; i++){
        cin >> element;
        vector.setElement(i, element);
    }
}

void display(Vector<int>& vector){
    vector.print();
}

void add(Vector<int>& v1, Vector<int>& v2){
    v1 += v2;
    cout << "done" << endl;
}

void subtract(Vector<int>& v1, Vector<int>& v2){
    v1 -= v2;
    cout << "done" << endl;
}

void multiplyByNumber(Vector<int>& vector){
    int number;
    cout << "enter number: ";
    cin >> number;
    vector *= number;
    cout << "done" << endl;
}

void divideByNumber(Vector<int>& vector){
    int number;
    cout << "enter number: ";
    cin >> number;
    vector /= number;
    cout << "done" << endl;
}

void printElement(Vector<int>& vector){
    int index;
    cout << "enter index: ";
    cin >> index;
    cout << vector[index] << endl;
}

int main()
{
    int command = -1;

    Vector<int> A;
    Vector<int> B;

    displayMenu();

    while (command != 0){
        cin >> command;
        try{
            switch(command){
                case 1:
                    enter(A);
                    break;
                case 2:
                    enter(B);
                    break;
                case 3:
                    display(A);
                    break;
                case 4:
                    display(B);
                    break;
                case 5:
                    add(A, B);
                    break;
                case 6:
                    add(B, A);
                    break;
                case 7:
                    subtract(A, B);
                    break;
                case 8:
                    subtract(B, A);
                    break;
                case 9:
                    multiplyByNumber(A);
                    break;
                case 10:
                    multiplyByNumber(B);
                    break;
                case 11:
                    divideByNumber(A);
                    break;
                case 12:
                    divideByNumber(B);
                    break;
                case 13:
                    printElement(A);
                    break;
                case 14:
                    printElement(B);
                    break;
                default:
                    break;
            }
        } catch (const char* message) {
             cout << message << endl;
        }
    }
    return 0;

}
