/**

Задача:
Разработать шаблон класса типа «BinarySearchTree» - бинарное поисковое дерево для построения частотного словаря.
Разработать ООП приложение для чтения данных из файла. Построения частотного словаря для этих данных, и поиска данных в этом словаре.
Примечание:
	•	Использовать исключения.
	•	Тестировать приложение для разных типов данных – числа целые, дробные, строки, символы.
**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "Node.h"
#include "Manager.h"
#include "BinarySearchTree.h"

using namespace std;

void printMenu() {
    cout << "Enter" << endl;
    cout << "1 to create dictionary" << endl;
    cout << "2 to find item in dictionary" << endl;
    cout << "3 to add item to dictionary" << endl;
    cout << "4 to remove item from dictionary" << endl;
    cout << "5 to delete dictionary" << endl;
    cout << "6 to print menu" << endl;
    cout << "0 to exit" << endl;
}

void enterFile(string& filename) {
    cout << "Enter filename with extension: ";
    cin >> filename;
}

void enterItem(double& item) {
    cout << "Enter item: ";
    cin >> item;
}


int main()
{
    Manager<double>* manager;
    Node<double>* foundItem;
    int selectedItem;
    double item;
    bool isSuccessful;
    string filename;
    string pathToProject;
    cout << "Enter path to project" << endl;
    cin >> pathToProject;

    manager = new Manager<double>(pathToProject);

    printMenu();

    selectedItem = 1;

    while (selectedItem != 0) {
        cin >> selectedItem;

        switch(selectedItem) {
            case 0:
                cout << "Exit" << endl;
                break;
            case 1:
                enterFile(filename);
                manager->createBinarySearchTree(filename);
                break;
            case 2:
                enterItem(item);
                isSuccessful = true;
                foundItem = new Node<double>(manager->findItem(item, isSuccessful));
                if (isSuccessful) {
                    cout << item << " found. Frequency: " << foundItem->getCounter() << endl;
                }
                break;
            case 3:
                enterItem(item);
                if (manager->addItem(item)) {
                    cout << "done" << endl;
                }
                break;
            case 4:
                enterItem(item);
                if (manager->deleteItem(item)) {
                    cout << "done" << endl;
                }
                break;
            case 5:
                if (manager->clearBinarySearchTree()) {
                    cout << "done" << endl;
                }
                break;
            case 6:
                printMenu();
                break;
            default:
                break;
        }
    }

    return 0;
}
