#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Fish.h"

using namespace std;

class Fisherman {
private:
    string surname_;
    string name_;
    int age_;
    vector<Fish> fishes_;
public:
    Fisherman();
    Fisherman(string surname, string name, int age);
    Fisherman(const Fisherman &source);
    string getSurname() const;
    string getName() const;
    int getAge() const;
    vector<Fish>& getFishes();
    void setSurname(string surname);
    void setName(string name);
    void setAge(int age);
    void addFish(const Fish &fish);
    double getTotalWeight() const;
    void clearFish();
    friend ostream& operator << (ostream& s, const Fisherman& fisherman);
    Fisherman& operator *= (double n);
};
