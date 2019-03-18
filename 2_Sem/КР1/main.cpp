#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <numeric>
#include <sstream>

#include "FileLib.h"
#include "Fisherman.h"

using namespace std;

Fisherman& parseFisherman(Fisherman &item, string sFisherman, string sFish) {
    string surname;
    string name;
    int age;

    string type;
    double weight;

    stringstream ss;
    ss << sFisherman;
    ss >> surname >> name >> age;
    item.setSurname(surname);
    item.setName(name);
    item.setAge(age);

    ss << sFish;
    item.clearFish();
    while (ss >> type >> weight) {
        item.addFish(Fish(type, weight));
    }
    return item;
}

void printTotalFishermenWeight(ostream_iterator<Fisherman>& out, multimap<int, Fisherman> fishermen) {
    vector<Fisherman> fishermenVector;
    transform(fishermen.begin(), fishermen.end(), back_inserter(fishermenVector),
            [](std::pair<int, Fisherman> const & pair) {
        return pair.second;
    });
    copy(fishermenVector.begin(), fishermenVector.end(), out);
}

bool printTheBestFishermanInAgeCategory(ofstream &fout, multimap<int, Fisherman> fishermen,
        multimap<int, Fisherman>::iterator lowBound, multimap<int, Fisherman>::iterator highBound) {
    if (lowBound != highBound) {
        fout << (*max_element(lowBound, highBound,
                              [](const pair<int, Fisherman> &fRight, const pair<int, Fisherman> &fLeft) {
                                  return fRight.second.getTotalWeight() < fLeft.second.getTotalWeight();
                              })).second;
        return true;
    } else {
        return false;
    }
}

vector<Fisherman>& addWeightWithCoefficientsToVector(multimap<int, Fisherman> &fishermen,
                                                     vector<Fisherman>& fishermenVector, multimap<int, Fisherman>::iterator lowBound,
                                                     multimap<int, Fisherman>::iterator highBound, double coefficient) {
    transform(lowBound, highBound, back_inserter(fishermenVector),
              [coefficient](const std::pair<int, Fisherman> & pair) {
                  Fisherman fis(pair.second);
                  fis *= coefficient;
                  return (Fisherman(pair.second) *= coefficient);
              });
    return fishermenVector;
}

void printTotalFishermenWeightWithCoefficients(ostream_iterator<Fisherman>& out,
        multimap<int, Fisherman> fishermen) {
    vector<Fisherman> fishermenVector;
    addWeightWithCoefficientsToVector(fishermen, fishermenVector, fishermen.begin(), fishermen.lower_bound(18), 1.1);
    addWeightWithCoefficientsToVector(fishermen, fishermenVector, fishermen.upper_bound(18), fishermen.lower_bound(30), 1);
    addWeightWithCoefficientsToVector(fishermen, fishermenVector, fishermen.upper_bound(30), fishermen.end(), 0.9);
    copy(fishermenVector.begin(), fishermenVector.end(), out);
}

void printSortedFishermen(ostream_iterator<Fisherman>& out,
        multimap<int, Fisherman> fishermen) {
    vector<Fisherman> fishermenVector;
    transform(fishermen.begin(), fishermen.end(), back_inserter(fishermenVector),
              [](std::pair<int, Fisherman> const & pair) {
                  return pair.second;
              });
    std::sort(fishermenVector.begin(), fishermenVector.end(), [](const Fisherman &a, const Fisherman &b) {
        if (a.getAge() != b.getAge()) {
            return a.getAge() < b.getAge();
        } else {
            return a.getSurname() < b.getSurname();
        }
    });
    copy(fishermenVector.begin(), fishermenVector.end(), out);
}

int main()
{
    bool doesAtLeastOneFileExist = false;
    bool result;
    int currentYear = 2019;
    string inputFileName = "";
    string outputFileName = "";
    int period = 10;
    multimap<int, Fisherman> fishermen;
    Fisherman item;
    string type;
    double weight;

    string sFisherman;
    string sFish;
    ifstream fin;
    ofstream fout;
    string error;

    for (int i = currentYear; i > currentYear - period; i--) {
        inputFileName = "fishers" + to_string(i) + ".txt";
        outputFileName = "output" + to_string(i) + ".txt";
        ostream_iterator<Fisherman> out(fout, "\n");

        fin.open(inputFileName);

        if (validateFile(fin, error)) {
            fout.open(outputFileName);
            doesAtLeastOneFileExist = true;
            fishermen.clear();

            while (getline(fin, sFisherman)) {
                getline(fin, sFish);
                parseFisherman(item, sFisherman, sFish);
                fishermen.insert(pair<int, Fisherman>(item.getAge(), item));
            }

            fout << "Total fishermen weights" << endl;
            printTotalFishermenWeight(out, fishermen);

            fout << endl << "The best fisherman under 18" << endl;
            result = printTheBestFishermanInAgeCategory(fout, fishermen, fishermen.begin(), fishermen.lower_bound(18));
            if (!result) {
                fout << "No fishermen under 18" << endl;
            }
            fout << endl;

            fout << endl << "The best fisherman from 18 to 30" << endl;
            result = printTheBestFishermanInAgeCategory(fout, fishermen, fishermen.upper_bound(18), fishermen.lower_bound(30));
            if (!result) {
                fout << "No fishermen from 18 to 30" << endl;
            }
            fout << endl;

            fout << endl << "The best fisherman after 30" << endl;
            result = printTheBestFishermanInAgeCategory(fout, fishermen, fishermen.upper_bound(30), fishermen.end());
            if (!result) {
                fout << "No fishermen after 30" << endl;
            }
            fout << endl;

            fout << endl << "Sorted fishermen by age" << endl;
            printSortedFishermen(out, fishermen);

            fout << endl << "New total weights with coefficients" << endl;
            printTotalFishermenWeightWithCoefficients(out, fishermen);

        }

        fin.close();
        fout.close();
    }

    if (!doesAtLeastOneFileExist) {
        cout << "No files or all files are empty !" << endl;
    }
    return 0;
}