#ifndef LAB_FLOWERBED_H
#define LAB_FLOWERBED_H

#include <vector>
#include <string>
#include <set>

using namespace std;

class FlowerBed {
private:
    int flowerBedNumber_;
    string shape_;
    vector<string> flowers_;
public:
    FlowerBed();
    FlowerBed(int flowerBedNumber, string shape, vector<string> flowers);
    FlowerBed(const FlowerBed& flowerBed);
    int getFlowerBedNumber() const;
    string getShape() const;
    vector<string> getFlowers() const;
    void setFlowerBedNumber(int flowerBedNumber);
    void setShape(string shape);
    void setFlowers(vector<string> flowers);
    int getNumberOfDifferentFlowers() const;
    friend std::ostream& operator << (std::ostream &stream, const FlowerBed &flowerBed);
};


#endif //LAB_FLOWERBED_H
