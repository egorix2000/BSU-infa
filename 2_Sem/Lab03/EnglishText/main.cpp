#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "FileLib.h"

using namespace std;

void printWordsFrequency(set<string> wordsSet, multiset<string> wordsMultiset) {
    cout << "Frequency" << endl;
    for (std::set<string>::iterator i = wordsSet.begin(); i != wordsSet.end(); i++) {
        std::cout << *i << ": " << wordsMultiset.count(*i) << endl;
    }
}

int main()
{
    set<string> wordsSet;
    multiset<string> wordsMultiset;
    string word;

    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (fin >> word){
            wordsSet.insert(word);
            wordsMultiset.insert(word);
        }

        cout << "Number of different words: " << wordsSet.size() << endl;

        printWordsFrequency(wordsSet, wordsMultiset);

    } else {
        cout << error << endl;
    }

    fin.close();
}