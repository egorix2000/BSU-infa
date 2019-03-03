#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include "FileLib.h"

using namespace std;

set<string>& parseString(set<string> &fishes, string s) {
    stringstream ss;
    string fish;
    ss << s;
    while (ss >> fish) {
        fishes.insert(fish);
    }
    return fishes;
}

void printFishermen(vector< set<string> > &fishermen) {
    cout << "Fishermen’s catch (species): " << endl;
    for (int i = 0; i < fishermen.size(); i++) {
        cout << "Fisherman " << i+1 << ": ";
        for (set<string>::iterator it = fishermen[i].begin(); it != fishermen[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void printCaughtSpecies(vector< set<string> > &fishermen, set<string> &caughtFish) {
    cout << "Caught species: " << endl;
    for (int i = 0; i < fishermen.size(); i++) {
        set_union (caughtFish.begin(), caughtFish.end(), fishermen[i].begin(), fishermen[i].end(), inserter(caughtFish, caughtFish.begin()));
    }
    for (set<string>::iterator it = caughtFish.begin(); it != caughtFish.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printNotCaughtSpecies(set<string> &caughtFish, set<string> &fishInLake) {
    set<string> result;
    cout << "Not caught species: " << endl;
    set_difference (fishInLake.begin(), fishInLake.end(), caughtFish.begin(), caughtFish.end(), inserter(result, result.begin()));
    for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    set<string> fishInLake;
    set<string> caughtFish;
    set<string> fishes;
    vector< set<string> > fishermen;

    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        getline(fin, line);
        parseString(fishInLake, line);

        while (getline(fin, line)){
            fishes.clear();
            parseString(fishes, line);
            fishermen.push_back(fishes);
        }

        printFishermen(fishermen);

        cout << endl;
        printCaughtSpecies(fishermen, caughtFish);

        cout << endl;
        printNotCaughtSpecies(caughtFish, fishInLake);

    } else {
        cout << error << endl;
    }

    fin.close();
}