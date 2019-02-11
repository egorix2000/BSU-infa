#include <iostream>
#include <fstream>
#include "FileLib.h"
#include "Set.h"

using namespace std;

void printMenu() {
    cout << "Enter" << endl;
    cout << "1 to load data from files" << endl;
    cout << "2 to add element to set" << endl;
    cout << "3 to remove element from set" << endl;
    cout << "4 to write intersection into file" << endl;
    cout << "5 to write union into file" << endl;
    cout << "6 to write difference into file" << endl;
    cout << "7 to determine if set2 includes set1" << endl;
    cout << "8 to determine are they equivalent" << endl;
    cout << "0 to exit" << endl;
}

void printSet(Set& set){
    char* e = new char[256];
    strcpy(e, set.getElements());
    for (int i = 0; i < strlen(e); i++){
        cout << e[i] << " ";
    }
    cout << endl;
}

void loadOneSet(Set& set, string file) {
    ifstream fin;
    fin.open(file);

    try {
        validateFile(fin);
        set.clearElements();
        fin >> set;
    } catch (string e) {
        cout << "File: " << file << ". " << e << endl;
    }
    fin.close();
}


void load(Set& set1, Set& set2) {
    string file;

    cout << "Enter full path to file and filename with extension to load first set: "; // example: /Users/apple/Documents/Project/input.txt
    cin >> file;
    loadOneSet(set1, file);

    cout << "Enter full path to file and filename with extension to load second set: "; // example: /Users/apple/Documents/Project/input.txt
    cin >> file;
    loadOneSet(set2, file);
}

void addElement(Set& set1, Set& set2) {
    int selectedItem;
    char element;
    cout << "Enter element: " << endl;
    cin >> element;
    cout << "Enter" << endl;
    cout << "1 to add element to first set" << endl;
    cout << "2 to add element to second set" << endl;
    cin >> selectedItem;
    switch (selectedItem){
        case 1:
            set1.addElement(element);
            break;
        case 2:
            set2.addElement(element);
            break;
        default:
            break;
    }
}

void removeElement(Set& set1, Set& set2) {
    int selectedItem;
    char element;
    cout << "Enter element: " << endl;
    cin >> element;
    cout << "Enter" << endl;
    cout << "1 to remove element from first set" << endl;
    cout << "2 to remove element from second set" << endl;
    cin >> selectedItem;
    switch (selectedItem){
        case 1:
            set1.removeElement(element);
            break;
        case 2:
            set2.removeElement(element);
            break;
        default:
            break;
    }
}

void writeSetIntoFile(Set& set) {
    string file;
    cout << "Enter full path to file and filename with extension where to write result:  ";
    cin >> file;
    ofstream fout;
    fout.open(file);

    fout << set;

    fout.close();
}

void findIntersection(Set& set1, Set& set2) {
    Set set = set1 * set2;
    writeSetIntoFile(set);
}

void findUnion(Set& set1, Set& set2) {
    Set set = set1 + set2;
    writeSetIntoFile(set);
}

void findDifference(Set& set1, Set& set2) {
    Set set = set1 - set2;
    writeSetIntoFile(set);
}

void isSubset(Set& set1, Set& set2) {
    if (set1 < set2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void areEquivalent(Set& set1, Set& set2) {
    if (set1 == set2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void exit() {
    cout << "Exit" << endl;
}

int main()
{
    Set set1 = Set();
    Set set2 = Set();
    printMenu();
    int selectedItem = 1;

    while (selectedItem != 0) {
        cin >> selectedItem;
        switch (selectedItem) {
            case 0:
                exit();
                break;
            case 1:
                load(set1, set2);
                break;
            case 2:
                addElement(set1, set2);
                break;
            case 3:
                removeElement(set1, set2);
                break;
            case 4:
                findIntersection(set1, set2);
                break;
            case 5:
                findUnion(set1, set2);
                break;
            case 6:
                findDifference(set1, set2);
                break;
            case 7:
                isSubset(set1, set2);
                break;
            case 8:
                areEquivalent(set1, set2);
                break;
            case 9:
                printSet(set1);
                break;
            case 10:
                printSet(set2);
                break;
            default:
                break;
        }
    }
    return 0;
}
