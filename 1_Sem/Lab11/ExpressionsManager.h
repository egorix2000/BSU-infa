#pragma once
#ifndef EXPRESSIONSMANAGER_H_INCLUDED
#define EXPRESSIONSMANAGER_H_INCLUDED

#include <vector>
#include <string>

#include "RationalFractionOperation.h"
#include "RationalFraction.h"
#include "FileManager.h"

class ExpressionsManager {
    public:
        ExpressionsManager(std::string pathToFile);
        bool read(std::string fileName, std::string pathToFile = "");
        bool write(std::string fileName);
        bool calculate();
    private:
        const std::string logFile_;
        std::vector<RationalFractionOperation> operations_;
        std::vector<RationalFraction> results_;
        FileManager* fileManager_;
};

#endif // EXPRESSIONSMANAGER_H_INCLUDED
