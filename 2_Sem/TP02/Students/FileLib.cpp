#include <fstream>
#include <string>

using namespace std;

bool validateFile(ifstream& fin, string& error){
    bool isValid;
    if (fin){
        fin.seekg(0, ios::end);
        if (fin.tellg() != 0){
            isValid = true;
            fin.seekg(0, ios::beg);
        } else {
            error = "Error. File is empty.";
            isValid = false;
        }
    } else {
        error = "Error. File not found.";
        isValid = false;
    }
    return isValid;
}
