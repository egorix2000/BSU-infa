#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <deque>
#include <forward_list>
#include <numeric>

#include "FileLib.h"

using namespace std;

void countNumbersEqualTo(list<int> list, vector<long> vector, deque<short int> deque,
        forward_list<double> forward_list, int number) {
    cout << "Count of numbers equal to " << number << endl;
    cout << "List: " << count (list.begin(), list.end(), number) << endl;
    cout << "Vector: " << count (vector.begin(), vector.end(), number) << endl;
    cout << "Deque: " << count (deque.begin(), deque.end(), number) << endl;
    cout << "Forward list: " << count (forward_list.begin(), forward_list.end(), number) << endl;
}

void countNumbersMoreThan(list<int> list, vector<long> vector, deque<short int> deque, forward_list<double> forward_list, int number) {
    cout << "Count of numbers more than " << number << endl;
    cout << "List: " << count_if (list.begin(), list.end(), [number](int n) {
        return n > number ? true : false;
    }) << endl;
    cout << "Vector: " << count_if (vector.begin(), vector.end(), [number](long n) {
        return n > number ? true : false;
    }) << endl;
    cout << "Deque: " << count_if (deque.begin(), deque.end(), [number](short int n) {
        return n > number ? true : false;
    }) << endl;
    cout << "Forward list: " << count_if (forward_list.begin(), forward_list.end(), [number](double n) {
        return n > number ? true : false;
    }) << endl;
}

void countNumbers(list<int> list, vector<long> vector, deque<short int> deque, forward_list<double> forward_list) {
    cout << "Count of all numbers: " << endl;
    cout << "List: " << count_if (list.begin(), list.end(), [](int n) {
        return true;
    }) << endl;
    cout << "Vector: " << count_if (vector.begin(), vector.end(), [](long n) {
        return true;
    }) << endl;
    cout << "Deque: " << count_if (deque.begin(), deque.end(), [](short int n) {
        return true;
    }) << endl;
    cout << "Forward list: " << count_if (forward_list.begin(), forward_list.end(), [](double n) {
        return true;
    }) << endl;
}

void sum(list<int> list, vector<long> vector, deque<short int> deque, forward_list<double> forward_list) {
    cout << "Sum of numbers" << endl;
    cout << "List: " << accumulate (list.begin(), list.end(), 0) << endl;
    cout << "Vector: " << accumulate (vector.begin(), vector.end(), 0) << endl;
    cout << "Deque: " << accumulate (deque.begin(), deque.end(), 0) << endl;
    cout << "Forward list: " << accumulate (forward_list.begin(), forward_list.end(), 0) << endl;
}

void average(list<int> list, vector<long> vector, deque<short int> deque, forward_list<double> forward_list) {
    double count;
    cout << "Average value of numbers" << endl;
    count = count_if (list.begin(), list.end(), [](int n) {
        return true;
    });
    cout << "List: " << (double)accumulate (list.begin(), list.end(), 0) / count << endl;
    count = count_if (vector.begin(), vector.end(), [](int n) {
        return true;
    });
    cout << "Vector: " << (double)accumulate (vector.begin(), vector.end(), 0) / count << endl;
    count = count_if (deque.begin(), deque.end(), [](int n) {
        return true;
    });
    cout << "Deque: " << (double)accumulate (deque.begin(), deque.end(), 0) / count << endl;
    count = count_if (forward_list.begin(), forward_list.end(), [](double n) {
        return true;
    });
    cout << "Forward list: " << (double)accumulate (forward_list.begin(), forward_list.end(), 0) / count << endl;
}

int main()
{
    list<int> list;
    vector<long> vector;
    deque<short int> deque;
    forward_list<double> forward_list;
    ifstream fin;
    string error;
    int number;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (fin >> number){
            list.push_back(number);
            vector.push_back(number);
            deque.push_back(number);
            forward_list.push_front(number);
        }

        cout << "Numbers: ";
        for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i) {
            cout << *i << ' ';
        }
        cout << endl;

        //count of numbers equal to given
        cout << "Enter number: ";
        cin >> number;
        countNumbersEqualTo(list, vector, deque, forward_list, number);

        //count of numbers more than given
        cout << "Enter number: ";
        cin >> number;
        countNumbersMoreThan(list, vector, deque, forward_list, number);

        //count of all numbers
        countNumbers(list, vector, deque, forward_list);

        //count sum
        sum(list, vector, deque, forward_list);

        //count average
        average(list, vector, deque, forward_list);
    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}