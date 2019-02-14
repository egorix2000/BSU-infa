#include <iostream>
#include <fstream>
#include <list>
#include <string>

#include "FileLib.h"

using namespace std;

bool ruleFirstLetter(string s, char letter) {
    return s[0] == letter ? true : false;
}

void print (list<string>& words) {
    for (list<string>::iterator i = words.begin(); i != words.end(); i++) {
        std::cout << *i << ' ';
    }
    cout << endl;
}

void sort (list<string>& words) {
    words.sort();
}

void findAndPrint(list<string>& words, char letter, bool (*rule)(string s, char letter)) {
    for (list<string>::iterator i = words.begin(); i != words.end(); i++) {
        if (rule(*i, letter)) {
            std::cout << *i << ' ';
        }
    }
    cout << endl;
}

void findAndDelete(list<string>& words, char letter) {
    list<string>::iterator it1 = find_if(words.begin(), words.end(), [letter](string s) {
        return s[0] == letter ? true : false;
    });
    list<string>::iterator it2 = find_if(it1, words.end(), [letter](string s) {
        return s[0] != letter ? true : false;
    });
    words.erase(it1, it2);
    cout << endl;
}

int main()
{
    list<string> wordsFromText;
    char letter;
    ifstream fin;
    string error;
    string word;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (fin >> word){
            wordsFromText.push_back(word);
        }
        //sort
        sort(wordsFromText);

        //print sorted elements
        cout << "Sorted elements:" << endl;
        print(wordsFromText);

        //print elements starts with given letter
        cout << "Enter start letter: ";
        cin >> letter;
        cout << "Found elements:" << endl;
        findAndPrint(wordsFromText, letter, &ruleFirstLetter);

        //delete elements starts with given letter
        cout << "Enter start letter: ";
        cin >> letter;
        findAndDelete(wordsFromText, letter);
        cout << "Elements deleted" << endl;

        //print elements
        cout << "Elements after removing:" << endl;
        print(wordsFromText);
    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}