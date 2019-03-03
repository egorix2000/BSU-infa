#include <iostream>

#include "FlowerBed.h"

FlowerBed::FlowerBed() {
    flowerBedNumber_ = 0;
    shape_ = "";
}

FlowerBed::FlowerBed(int flowerBedNumber, string shape, vector<string> flowers) {
    flowerBedNumber_ = flowerBedNumber;
    shape_ = shape;
    for (int i = 0; i < flowers.size(); i++) {
        flowers_.push_back(flowers[i]);
    }
}

FlowerBed::FlowerBed(const FlowerBed &source) {
    flowerBedNumber_ = source.getFlowerBedNumber();
    shape_ = source.getShape();
    for (int i = 0; i < source.getFlowers().size(); i++) {
        flowers_.push_back(source.getFlowers()[i]);
    }
}

int FlowerBed::getFlowerBedNumber() const {
    return flowerBedNumber_;
}

string FlowerBed::getShape() const {
    return shape_;
}

vector<string> FlowerBed::getFlowers() const {
    return flowers_;
}

void FlowerBed::setFlowerBedNumber(int flowerBedNumber) {
    flowerBedNumber_ = flowerBedNumber;
}

void FlowerBed::setShape(string shape) {
    shape_ = shape;
}

void FlowerBed::setFlowers(vector<string> flowers) {
    flowers_.clear();
    for (int i = 0; i < flowers.size(); i++) {
        flowers_.push_back(flowers[i]);
    }
}

int FlowerBed::getNumberOfDifferentFlowers() const {
    set<string> unique;
    for (int i = 0; i < flowers_.size(); i++) {
        unique.insert(flowers_[i]);
    }
    return unique.size();
}

std::ostream &operator<<(std::ostream &stream, const FlowerBed &flowerBed) {
    cout << flowerBed.getFlowerBedNumber() << " " << flowerBed.getShape();
    for (int i = 0; i < flowerBed.getFlowers().size(); i++) {
        cout << " " << flowerBed.getFlowers()[i];
    }
    return stream;
}
