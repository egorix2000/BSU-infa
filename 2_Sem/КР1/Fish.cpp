#include "Fish.h"

Fish::Fish() {
    type_ = "";
    weight_ = 0;
}

Fish::Fish(string type, double weight) {
    type_ = type;
    weight_ = weight;
}

Fish::Fish(const Fish &fish) {
    type_ = fish.getType();
    weight_ = fish.getWeight();
}

string Fish::getType() const {
    return type_;
}

double Fish::getWeight() const {
    return weight_;
}

void Fish::setType(string type) {
    type_ = type;
}

void Fish::setWeight(double weight) {
    weight_ = weight;
}