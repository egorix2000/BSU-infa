/**

Написать рекурсивную функцию, определяющую, является ли симметричной часть строки s, начиная с i-го элемента и кончая j-м.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "FileLib.h"
#include "OneDimensionalArrayLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/isPalidrom/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/isPalidrom/output.txt";

bool isPalindrom(char* start, char* finish){
    if (start == finish || start-1 == finish || start+1 == finish){
        return true;
    }
    if (start[0] != finish[0]){
        return false;
    }
    return isPalindrom(start+1, finish-1);
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    char s[MAX_STRING_LENGTH];
    char missEnter[MAX_STRING_LENGTH];
    int start;
    int finish;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin.getline(s, MAX_STRING_LENGTH)){
            fin >> start >> finish;
            fin.getline(missEnter, MAX_STRING_LENGTH); // without this program reads from file enter after start and finish
            if (isPalindrom(s+start, s+finish)){
                fout << "Yes" << endl;
            } else {
                fout << "No" << endl;
            }
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
