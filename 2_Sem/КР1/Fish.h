#pragma once

#include <string>

using namespace std;

class Fish {
private:
    string type_;
    double weight_;
public:
    Fish();
    Fish(string type, double weight);
    Fish(const Fish &fish);
    string getType() const;
    double getWeight() const;
    void setType(string type);
    void setWeight(double weight);
};
