#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>

#include "FileLib.h"

using namespace std;

void printWordsStartedWith(vector<string>& words) {
    char c;
    cout << "Enter start-letter: ";
    cin >> c;
    cout << "Found words: " << endl;
    copy_if(words.begin(), words.end(), ostream_iterator<string>(std::cout, " "), [c](string s) {
        return s[0] == c;
    });
    cout << endl;
}

void deleteWords(vector<string>& words) {
    char c;
    cout << "Delete words. Enter start-letter: ";
    cin >> c;
    words.erase(remove_if(words.begin(), words.end(), [c](string s) {
        return s[0] == c;
    }), words.end());
}

void printWords(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << ' ';
    }
    cout << endl;
}

void printMap(map<string, int>& wordsMap) {
    for (std::map<string, int>::iterator it = wordsMap.begin(); it != wordsMap.end(); it++) {
        cout << "Word '" << it->first << "' found in the text " << it->second << " time";
        if (it->second != 1) {
            cout << "s";
        }
        cout << endl;
    }
    cout << endl;
}

map<string, int>& constructMap(map<string, int>& map, vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        map[words[i]]++;
    }
    return map;
}

int main()
{
    vector<string> words;
    string word;

    string error;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (fin >> word){
            words.push_back(word);
        }

        //sort
        sort(words.begin(), words.end());
        cout << "Sorted words: " << endl;
        printWords(words);

        //elements started with given letter
        printWordsStartedWith(words);

        //delete
        deleteWords(words);
        cout << "Deletion completed. New words: " << endl;
        printWords(words);

        //# different words
        set<string> differentWords (words.begin(), words.end());
        cout << "There are " << differentWords.size() << " different words" << endl;

        //# duplications
        map<string, int> wordsAndCounts;
        constructMap(wordsAndCounts, words);
        printMap(wordsAndCounts);

    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}