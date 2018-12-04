#pragma once
#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <iostream>
#include <fstream>

class Set {
    public:
        Set();
        ~Set();
        char* getElements() const;
        void setElements(char* elements);
        int getMaxSize() const;
        void clearElements();
        void addElement(char element);
        void removeElement(char element);
        Set operator = (const Set& set);
        friend std::ofstream& operator << (std::ofstream &fout, const Set& set);
        friend std::ifstream& operator >> (std::ifstream &stream, Set& set);
        friend std::istream& operator >> (std::istream &fin, Set& set);
        friend Set operator * (const Set& set1, const Set& set2);
        friend Set operator + (const Set& set1, const Set& set2);
        friend Set operator - (const Set& set1, const Set& set2);
        friend bool operator < (const Set& set1, const Set& set2);
        friend bool operator == (const Set& set1, const Set& set2);
    private:
        int maxSize_;
        char* elements_;
};

#endif // SET_H_INCLUDED
