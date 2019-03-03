#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

#include "FileLib.h"

using namespace std;

void sortLexicographically(vector<string> &words) {
    deque<string> mainQueue;
    string currentWord;
    vector< deque<string> > blocks (26); // associated with letters a ... z
    int maxLength = (*max_element(words.begin(), words.end(), [](const string s1, const string s2) {
        return s1.length() < s2.length();
    })).length();
    for (int i = maxLength; i > 0; i--) {
        cout << i << " ";
        for (int j = 0; j < words.size(); j++) {
            if (words[j].length() == i) {
                mainQueue.push_front(words[j]);
            }
        }

        while (!mainQueue.empty()) {
            currentWord = mainQueue.front();
            cout << currentWord << " ";
            mainQueue.pop_front();
            blocks[currentWord[i-1]-'a'].push_back(currentWord);
        }
        cout << endl;

        for (int j = 0; j < blocks.size(); j++) {
            while (!blocks[j].empty()) {
                currentWord = blocks[j].front();
                blocks[j].pop_front();
                mainQueue.push_back(currentWord);
            }
        }
    }
    words.clear();
    while (!mainQueue.empty()) {
        currentWord = mainQueue.front();
        mainQueue.pop_front();
        words.push_back(currentWord);
    }
}

int main() {
    vector<string> words;
    string word;

    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)) {

        while (fin >> word) {
            words.push_back(word);
        }

        sortLexicographically(words);

        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << endl;
        }

    } else {
        cout << error << endl;
    }

    fin.close();
}