#include <iostream>
#include "ExpressionsManager.h"
#include "FileException.h"
#include "Exception.h"

using namespace std;

void printMenu() {
    cout << "Enter" << endl;
    cout << "1 to load data from file" << endl;
    cout << "2 to calculate result" << endl;
    cout << "3 to write into file" << endl;
    cout << "4 to print menu" << endl;
    cout << "0 to exit" << endl;
}

void printFileMenu() {
    cout << "Enter" << endl;
    cout << "1 to load data from file in project folder" << endl;
    cout << "2 to load data from file not in project folder" << endl;
}

bool read(ExpressionsManager* expressionsManager) {
    printFileMenu();
    string fileName;
    string pathToFile = "";
    int selectedItem = 0;
    cin >> selectedItem;
    switch (selectedItem) {
        case 1:
            cout << "Enter fileName with extension" << endl;
            cin >> fileName;
            break;
        case 2:
            cout << "Enter fileName with extension" << endl;
            cin >> fileName;
            cout << "Enter path to file" << endl;
            cin >> pathToFile;
            break;
        default:
            break;
    }

    return expressionsManager->read(fileName, pathToFile);
}

bool write (ExpressionsManager* expressionsManager) {
    string fileName;
    cout << "Enter file name" << endl;
    cin >> fileName;
    return expressionsManager->write(fileName);
}

bool calculate (ExpressionsManager* expressionsManager) {
    return expressionsManager->calculate();
}

int main()
{
    string pathToProject;
    cout << "Enter path to project" << endl;
    cin >> pathToProject;

    ExpressionsManager* expressionsManager = new ExpressionsManager(pathToProject);
    printMenu();
    int selectedItem = 4;

    while (selectedItem != 0) {
        cin >> selectedItem;

        switch(selectedItem) {
            case 0:
                cout << "Exit" << endl;
                break;
            case 1:
                if (read(expressionsManager)) {
                    cout << "done" << endl;
                } else {
                    cout << "Something wrong with file. Check log.txt" << endl;
                }
                break;
            case 2:
                calculate(expressionsManager);
                cout << "done" << endl;
                break;
            case 3:
                write(expressionsManager);
                cout << "done" << endl;
                break;
            case 4:
                printMenu();
                break;
            default:
                break;
        }
    }
    return 0;
}
