#include <iostream>
#include <string>
#include <cmath>

#include "Set/Set.h"
#include "Set/SetException.h"

using namespace std;

int main()
{
    string initStr[5] = {"2_first", "5_second", "8_third", "a_fourth", "p_fifth"};

    cout << "Set1" << endl;
    Set<int> set1;

    for (int i = 0; i < 10; i++) {
        set1.addElement(i + 1);
    }
    set1.show();
    set1.addElement(5);
    set1.addElement(13);
    set1.show();

    try {
        cout << "Set2" << endl;
        Set<string> set2;
        for (int i = 0; i < 5; i++) {
            set2.addElement(initStr[i]);
        }
        set2.show();
        set2.addElement("9_after_third");
        set2.show();
        cout << set2[6] << endl;
        set2.show();

    } catch (SetException& e) {
        cout << e.execute() << endl;
    }

    try {
        cout << "Set3" << endl;
        Set<double> set3;
        set3.addElement(2.1);
        set3.addElement(5.3);
        set3.addElement(1.5);
        set3.show();
        set3.deleteElement(5.3);
        set3.show();
        set3.deleteElement(2.0);
    } catch (SetException& e) {
        cout << e.execute() << endl;
    }
    return 0;
}