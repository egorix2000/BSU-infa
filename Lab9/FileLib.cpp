#include <fstream>
#include <cstring>

using namespace std;

bool validateFile(ifstream& fin, char* error){
    bool isValid;
    if (fin){
        fin.seekg(0, ios::end);
        if (fin.tellg() != 0){
            isValid = true;
            fin.seekg(0, ios::beg);
        } else {
            strcpy(error, "Error. File is empty.");
            isValid = false;
        }
    } else {
        strcpy(error, "Error. File not found.");
        isValid = false;
    }
    return isValid;
}
