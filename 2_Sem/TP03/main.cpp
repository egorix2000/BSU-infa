#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

#include "FileLib.h"
#include "FlowerBed.h"

using namespace std;

FlowerBed& parseString(FlowerBed& flowerBed, string s) {
    stringstream ss;
    int flowerBedNumber;
    string shape;
    string flower;
    vector<string> flowers;
    ss << s;
    ss >> flowerBedNumber >> shape;
    flowerBed.setFlowerBedNumber(flowerBedNumber);
    flowerBed.setShape(shape);
    while (ss >> flower) {
        flowers.push_back(flower);
    }
    flowerBed.setFlowers(flowers);
    return flowerBed;
}

void printFlowerBeds(vector<FlowerBed>& flowerBeds) {
    std::ostream_iterator<FlowerBed> out(std::cout, "\n");
    std::copy ( flowerBeds.cbegin(), flowerBeds.cend(), out );
}

multimap<string, FlowerBed> fillMapFromVector(multimap<string, FlowerBed> &flowerBedsMap,
        vector<FlowerBed> &flowerBeds) {
    for (int i = 0; i < flowerBeds.size(); i++) {
        flowerBedsMap.insert(pair<string, FlowerBed>(flowerBeds[i].getShape(), flowerBeds[i]));
    }
    return flowerBedsMap;

}

void printAllDifferentShapes(multimap<string, FlowerBed> &flowerBedsMap) {
    cout << "All different shapes:" << endl;
    vector<string> allShapes;
    vector<string> unique;

    transform(flowerBedsMap.begin(), flowerBedsMap.end(), inserter(allShapes, allShapes.begin()),
              [](const std::multimap<string, FlowerBed>::value_type &pair) {
                  return pair.first;
              });

    unique_copy(allShapes.begin(), allShapes.end(), inserter(unique, unique.begin()),
            [](const string &entry1,
               const string &entry2){
        return (entry1 == entry2);
    });

    std::ostream_iterator<string> out(std::cout, "\n");
    std::copy ( unique.cbegin(), unique.cend(), out );
    cout << endl;
}

void printAllFlowersFromFlowerBed(vector<FlowerBed> &flowerBeds) {
    int n;
    cout << "Enter number of flower bed: ";
    cin >> n;
    FlowerBed &flowerBed = *find_if(flowerBeds.begin(), flowerBeds.end(), [n](const FlowerBed& flowerBed) {
        return flowerBed.getFlowerBedNumber() == n;
    });

    cout << "All flowers from this flower bed: " << endl;

    vector<string> flowers = vector<string>(flowerBed.getFlowers());

    std::ostream_iterator<string> out(std::cout, " ");
    std::copy ( flowers.begin(), flowers.end(), out );

    cout << endl;
}

void printAllDifferentFlowers(vector<FlowerBed> &flowerBeds) {
    set<string> uniqueFlowers;
    for (int i = 0; i < flowerBeds.size(); i++) {
        for (int j = 0; j < flowerBeds[i].getFlowers().size(); j++) {
            uniqueFlowers.insert(flowerBeds[i].getFlowers()[j]);
        }
    }

    cout << "All types of flowers:" << endl;
    for (set<string>::iterator it = uniqueFlowers.begin(); it != uniqueFlowers.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printBedWithMaxFlowers(vector<FlowerBed> &flowerBeds) {
    cout << "Flower bed with max number of flowers:" << endl;
    cout << *max_element(flowerBeds.begin(), flowerBeds.end(), [](const FlowerBed &entry1, const FlowerBed &entry2) {
        return entry2.getFlowers().size() > entry1.getFlowers().size();
    }) << endl;
}

void printBedWithGivenNumberOfFlowers(vector<FlowerBed> &flowerBeds) {
    int n;
    vector<FlowerBed> flowerBedsWithGivenNumberOfFlowers;
    cout << "Enter number of flowers: ";
    cin >> n;
    copy_if(flowerBeds.begin(), flowerBeds.end(),
            inserter(flowerBedsWithGivenNumberOfFlowers, flowerBedsWithGivenNumberOfFlowers.begin()),
            [n](FlowerBed &flowerBed) {
        return flowerBed.getFlowers().size() == n;
    });
    cout << "All beds with given number of flowers:" << endl;

    std::ostream_iterator<FlowerBed> out(std::cout, "\n");
    std::copy ( flowerBedsWithGivenNumberOfFlowers.begin(), flowerBedsWithGivenNumberOfFlowers.end(), out );
}

void printBedWithOnlyOneTypeOfFlower(vector<FlowerBed> &flowerBeds) {
    cout << "Bed with only one type of flowers: " << endl;
    cout << *find_if(flowerBeds.begin(), flowerBeds.end(), [](FlowerBed &flowerBed) {
        return flowerBed.getNumberOfDifferentFlowers() == 1;
    }) << endl;
}

void printBedWithMaxTypesOfFlowers(vector<FlowerBed> &flowerBeds) {
    cout << "Flower bed with max number of types of flowers:" << endl;
    cout << *max_element(flowerBeds.begin(), flowerBeds.end(), [](const FlowerBed &entry1, const FlowerBed &entry2) {
        return entry2.getNumberOfDifferentFlowers() > entry1.getNumberOfDifferentFlowers();
    }) << endl;
}

void printNumberOfFlowersOnCircleBeds(multimap<string, FlowerBed> &flowerBedsMap) {
    int n = 0;
    pair <std::multimap<string, FlowerBed>::iterator, std::multimap<string, FlowerBed>::iterator> ret;
    ret = flowerBedsMap.equal_range("circle");
    for (std::multimap<string, FlowerBed>::iterator it = ret.first; it != ret.second; it++) {
        n += (*it).second.getFlowers().size();
    }
    cout << "Number of flowers on circle beds: " << n << endl;
}

void printAllBedsWithGivenShape(multimap<string, FlowerBed> &flowerBedsMap) {
    string shape;
    cout << "Enter shape of flower bed: ";
    cin >> shape;
    cout << "Flower beds with shape '" << shape << "': " << endl;
    pair <std::multimap<string, FlowerBed>::iterator, std::multimap<string, FlowerBed>::iterator> ret;
    ret = flowerBedsMap.equal_range(shape);
    for (std::multimap<string, FlowerBed>::iterator it = ret.first; it != ret.second; it++) {
        cout << (*it).second << endl;
    }
}

int main()
{
    FlowerBed flowerBed;
    vector<FlowerBed> flowerBeds;
    multimap<string, FlowerBed> flowerBedsMap;
    int flowerBedNumber;
    string shape;

    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (getline(fin, line)){
            parseString(flowerBed, line);
            flowerBeds.push_back(flowerBed);
        }
        sort(flowerBeds.begin(), flowerBeds.end(), [](FlowerBed &flowerBedLeft, FlowerBed &flowerBedRight) {
            return flowerBedLeft.getShape() < flowerBedRight.getShape();
        });

        cout << "Sorted by shape: " << endl;
        printFlowerBeds(flowerBeds);

        fillMapFromVector(flowerBedsMap, flowerBeds);

        cout << endl;
        printAllDifferentShapes(flowerBedsMap);

        cout << endl;
        printAllFlowersFromFlowerBed(flowerBeds);

        cout << endl;
        printAllDifferentFlowers(flowerBeds);

        cout << endl;
        printBedWithMaxFlowers(flowerBeds);

        cout << endl;
        printBedWithGivenNumberOfFlowers(flowerBeds);

        cout << endl;
        printBedWithOnlyOneTypeOfFlower(flowerBeds);

        cout << endl;
        printBedWithMaxTypesOfFlowers(flowerBeds);

        cout << endl;
        printNumberOfFlowersOnCircleBeds(flowerBedsMap);

        cout << endl;
        printAllBedsWithGivenShape(flowerBedsMap);
    } else {
        cout << error << endl;
    }

    fin.close();
}