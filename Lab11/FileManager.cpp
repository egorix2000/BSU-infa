#include <string>
#include <vector>

#include "FileManager.h"
#include "EmptyFileException.h"
#include "FileNotFoundException.h"

FileManager::FileManager(std::string pathToProject) {
    pathToProject_ = pathToProject;
}

bool FileManager::validate() {
    bool isValid;
    fin_.open(pathToFile_ + fileName_);
    if (fin_) {
        if (fin_.peek() != std::ifstream::traits_type::eof()) {
            isValid = true;
        } else {
            throw EmptyFileException();
            //isValid = false;
        }
    } else {
        throw FileNotFoundException();
        //isValid = false;
    }
    fin_.close();
    return isValid;
}

std::vector<std::string> FileManager::read() {
    std::vector<std::string> data;
    std::string line;
    fin_.open(pathToFile_ + fileName_);
    while (getline(fin_, line)) {
        data.push_back(line);
    }
    fin_.close();
    return data;
}

void FileManager::writeLine(std::string s) {
    fout_.open(pathToProject_ + fileName_, std::ios::app);
    fout_ << s << '\n';
    fout_.close();
}

void FileManager::setFile(std::string fileName, std::string pathToFile) {
    if (pathToFile == "") {
        pathToFile_ = pathToProject_;
    } else {
        pathToFile_ = pathToFile;
    }
    fileName_ = fileName;
}

std::string FileManager::getFileName() {
    return fileName_;
}
