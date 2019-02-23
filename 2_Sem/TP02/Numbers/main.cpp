#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "FileLib.h"

using namespace std;

int findMax(vector<int>& numbers) {
    return *max_element(numbers.begin(), numbers.end());
}

void printCountOfNumbersEqualTo(vector<int>& numbers) {
    int n;
    int count;
    cout << "Enter number: ";
    cin >> n;
    count = std::count(numbers.begin(), numbers.end(), n);
    cout << "There are " << count << " numbers equal to " << n << endl;
}

void printCountOfNumbersGreaterThan(vector<int>& numbers) {
    int n;
    int count;
    cout << "Enter number: ";
    cin >> n;
    count = count_if(numbers.begin(), numbers.end(), [n](int i){
        return i > n;
    });
    cout << "There are " << count << " numbers more than " << n << endl;
}

int main()
{
    vector<int> numbers;
    int number;
    int sum;

    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (fin >> number){
            numbers.push_back(number);
        }

        //find max
        cout << "Max number: " << findMax(numbers) << endl;

        //# numbers equal to given
        printCountOfNumbersEqualTo(numbers);

        //# numbers greater than 15
        printCountOfNumbersGreaterThan(numbers);

        //# all numbers
        cout << "There are " << numbers.size() << " numbers" << endl;

        //sum
        sum = accumulate(numbers.begin(), numbers.end(), 0);
        cout << "Sum of numbers is " << sum << endl;

        //average
        cout << "Average of numbers is " << (double) sum/(double) numbers.size() << endl;

    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}