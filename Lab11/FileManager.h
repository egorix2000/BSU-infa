#pragma once
#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <fstream>

class FileManager {
    public:
        FileManager(std::string pathToProject);
        bool validate();
        std::vector<std::string> read();
        void writeLine(std::string s);
        void setFile(std::string fileName, std::string pathToFile = "");
        std::string getFileName();
    private:
        std::ifstream fin_;
        std::ofstream fout_;
        std::string fileName_;
        std::string pathToFile_;
        std::string pathToProject_;
};

#endif // FILEMANAGER_H_INCLUDED
