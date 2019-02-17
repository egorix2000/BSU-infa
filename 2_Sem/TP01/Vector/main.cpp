#include <iostream>
#include <string>

#include "Vectorex/Vectorex.h"
#include "Vector/VectorException.h"

using namespace std;

int main()
{
    string initStr[5] = {"first", "second", "third", "fourth", "fifth"};

    cout << "V1" << endl;
    Vectorex<int> v1(10);
    for (int i = 0; i < v1.getSize(); i++) {
        v1[i] = i + 1;
    }
    v1.show();

    try {
        cout << "V2" << endl;
        Vectorex<string> v2(5);
        for (int i = 0; i < v2.getSize(); i++) {
            v2[i] = initStr[i];
        }
        v2.show();
        v2.addElement(3, "After_third");
        v2.show();
        v2.push_front("Begin");
        v2.show();
        v2.push_back("Add_1");
        v2.push_back("Add_2");
        v2.push_back("Add_3");
        v2.show();

        v2.pop();
        v2.pop();
        v2.show();
        cout << v2[6] << endl;
        cout << v2[7] << endl;
    } catch (VectorException& e) {
        cout << e.execute() << endl;
    }

    try {
        cout << "V3" << endl;
        Vectorex<int> v3;
        v3.push_back(21);
        v3.show();
        v3.pop();
        v3.pop();
        v3.show();
    } catch (VectorException& e) {
        cout << e.execute() << endl;
    }
    return 0;
}