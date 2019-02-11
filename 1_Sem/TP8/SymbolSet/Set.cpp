#include <iostream>
#include <fstream>
#include <cstring>
#include "Set.h"

Set::Set(): maxSize_(256) {
    elements_ = new char[maxSize_];
}

Set::~Set() {
    delete [] elements_;
}

char* Set::getElements() const {
    return elements_;
}

void Set::setElements(char* elements) {
    strcpy(elements_, elements);
}

int Set::getMaxSize() const {
    return maxSize_;
}

void Set::clearElements() {
    elements_ = new char[maxSize_];
}

void Set::addElement(char element) {
    if (!strchr(elements_, element)) {
        elements_[strlen(elements_)] = element;
        elements_[strlen(elements_)+1] = '\0';
    }
}

void Set::removeElement(char element) {
    char* toRemove = strchr(elements_, element);
    if (toRemove) {
        for (int i = toRemove - elements_; i < strlen(elements_)-1; i++) {
            elements_[i] = elements_[i+1];
        }
        elements_[strlen(elements_)-1] = '\0';
    }
}

Set Set::operator = (const Set& set) {
    strcpy(elements_, set.getElements());
    return *this;
}

std::ofstream& operator << (std::ofstream &fout, const Set& set) {
    char* elements = new char[set.getMaxSize()];
    strcpy(elements, set.getElements());
    fout << "{ ";
    for (int i = 0; i < strlen(elements); i++) {
        fout << elements[i] << ", ";
    }
    fout << "}" << '\n';
    delete [] elements;
    return fout;
}

std::istream& operator >> (std::istream &stream, Set& set) {
    char element;

    while (stream >> element) {
        if (element != ' ') {
            set.addElement(element);
        }
    }

    return stream;
}

std::ifstream& operator >> (std::ifstream &fin, Set& set) {
    char element;

    while (fin >> element) {
        if (element != ' ') {
            set.addElement(element);
        }
    }

    return fin;
}

Set operator * (const Set& set1, const Set& set2){
    Set intersection = Set();
    char* temp;
    char* elements1 = new char[set1.getMaxSize()];
    char* elements2 = new char[set2.getMaxSize()];

    strcpy(elements1, set1.getElements());
    strcpy(elements2, set2.getElements());
    for (int i = 0; i < strlen(elements1); i++) {
        temp = strchr(elements2, elements1[i]);
        if (temp) {
            intersection.addElement(elements1[i]);
        }
    }
    return intersection;
}

Set operator + (const Set& set1, const Set& set2){
    Set united = Set();
    char* elements1 = new char[set1.getMaxSize()];
    char* elements2 = new char[set2.getMaxSize()];

    strcpy(elements1, set1.getElements());
    strcpy(elements2, set2.getElements());
    for (int i = 0; i < strlen(elements1); i++) {
        united.addElement(elements1[i]);
    }
    for (int i = 0; i < strlen(elements2); i++) {
        united.addElement(elements2[i]);
    }
    return united;
}

Set operator - (const Set& set1, const Set& set2){
    Set difference = Set();
    char* temp;
    char* elements1 = new char[set1.getMaxSize()];
    char* elements2 = new char[set2.getMaxSize()];

    strcpy(elements1, set1.getElements());
    strcpy(elements2, set2.getElements());
    for (int i = 0; i < strlen(elements1); i++) {
        temp = strchr(elements2, elements1[i]);
        if (!temp) {
            difference.addElement(elements1[i]);
        }
    }
    return difference;
}

bool operator < (const Set& set1, const Set& set2) {
    bool isSubset = true;
    char* temp;
    char* elements1 = new char[set1.getMaxSize()];
    char* elements2 = new char[set2.getMaxSize()];

    strcpy(elements1, set1.getElements());
    strcpy(elements2, set2.getElements());

    for (int i = 0; i < strlen(elements1); i++) {
        temp = strchr(elements2, elements1[i]);
        if (temp) {
            elements2[temp - elements2 + 1] = ' ';
        } else {
            isSubset = false;
            break;
        }
    }
    delete [] elements1;
    delete [] elements2;
    return isSubset;
}

bool operator == (const Set& set1, const Set& set2) {
    if (strlen(set1.getElements()) == strlen(set2.getElements())) {
        return true;
    } else {
        return false;
    }
}
