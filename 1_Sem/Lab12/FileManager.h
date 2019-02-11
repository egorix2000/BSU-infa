#pragma once
#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <fstream>
#include "EmptyFileException.h"
#include "FileNotFoundException.h"

template <class T>
class FileManager {
    public:
        FileManager();
        FileManager(std::string pathToProject);
        FileManager(FileManager& sourse);
        bool validate();
        std::vector<T> read(std::vector<T>& data);
        void writeLine(std::string s);
        void setFile(std::string fileName);
        void setPathToProject(std::string pathToProject);
        std::string getPathToProject();
        std::string getFileName();
    private:
        std::ifstream fin_;
        std::ofstream fout_;
        std::string fileName_;
        std::string pathToProject_;
};

template <class T>
FileManager<T>::FileManager() {
    pathToProject_ = "";
}

template <class T>
FileManager<T>::FileManager(std::string pathToProject) {
    pathToProject_ = pathToProject;
}

template <class T>
FileManager<T>::FileManager(FileManager& sourse) {
    pathToProject_ = sourse.getPathToProject();
}

template <class T>
void FileManager<T>::setPathToProject(std::string pathToProject){
    pathToProject_ = pathToProject;
}

template <class T>
std::string FileManager<T>::getPathToProject(){
    return pathToProject_;
}

template <class T>
bool FileManager<T>::validate() {
    bool isValid;
    fin_.open(pathToProject_ + fileName_);
    if (fin_) {
        if (fin_.peek() != std::ifstream::traits_type::eof()) {
            isValid = true;
        } else {
            throw EmptyFileException();
            //isValid = false;
        }
    } else {
        throw FileNotFoundException(pathToProject_ + fileName_);
        //isValid = false;
    }
    fin_.close();
    return isValid;
}

template <class T>
std::vector<T> FileManager<T>::read(std::vector<T>& data) {
    T item;
    fin_.open(pathToProject_ + fileName_);
    while (fin_ >> item) {
        data.push_back(item);
    }
    fin_.close();
    return data;
}

template <class T>
void FileManager<T>::writeLine(std::string s) {
    fout_.open(pathToProject_ + fileName_, std::ios::app);
    fout_ << s << '\n';
    fout_.close();
}

template <class T>
void FileManager<T>::setFile(std::string fileName) {
    fileName_ = fileName;
}

template <class T>
std::string FileManager<T>::getFileName() {
    return fileName_;
}

#endif // FILEMANAGER_H_INCLUDED
