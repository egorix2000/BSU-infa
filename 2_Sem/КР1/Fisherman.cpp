#include <numeric>
#include <iomanip>
#include "Fisherman.h"

Fisherman::Fisherman() {
    surname_ = "";
    name_ = "";
    age_ = 0;
}

Fisherman::Fisherman(string surname, string name, int age) {
    surname_ = surname;
    name_ = name;
    age_ = age;
}

Fisherman::Fisherman(const Fisherman &source) {
    surname_ = source.getSurname();
    name_ = source.getName();
    age_ = source.getAge();
    fishes_.clear();
    for (vector<Fish>::iterator i = (const_cast<Fisherman&>(source)).getFishes().begin();
            i != (const_cast<Fisherman&>(source)).getFishes().end(); i++) {
        fishes_.push_back(*i);
    }
}

string Fisherman::getSurname() const {
    return surname_;
}

string Fisherman::getName() const {
    return name_;
}

int Fisherman::getAge() const {
    return age_;
}

vector<Fish>& Fisherman::getFishes() {
    return fishes_;
}

double Fisherman::getTotalWeight() const {
    return ((double) accumulate(fishes_.begin(), fishes_.end(), 0, [](int current, const Fish &toAdd){
        return current += toAdd.getWeight();
    }));
}

void Fisherman::setSurname(string surname) {
    surname_ = surname;
}

void Fisherman::setName(string name) {
    name_ = name;
}

void Fisherman::setAge(int age) {
    age_ = age;
}

void Fisherman::addFish(const Fish &fish) {
    fishes_.push_back(fish);
}

void Fisherman::clearFish() {
    fishes_.clear();
}

ostream& operator << (ostream& s, const Fisherman& fisherman) {
    s << setw(15) << fisherman.getSurname() << setw(15) << fisherman.getName() << setw(7) << fisherman.getAge() << " ";
    s << setw(10) << (double) accumulate((const_cast<Fisherman&>(fisherman)).getFishes().begin(),
            (const_cast<Fisherman&>(fisherman)).getFishes().end(), 0.0, [](double current, const Fish &toAdd){
        return current += toAdd.getWeight();
    });
    return s;
}

Fisherman& Fisherman::operator *= (double n) {
    double newWeight;
    for (vector<Fish>::iterator i = fishes_.begin(); i != fishes_.end(); i++) {
        newWeight = (*i).getWeight() * n;
        (*i).setWeight(newWeight);
    }
    return *this;
}