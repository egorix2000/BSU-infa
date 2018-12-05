#include <string>
#include <ctime>
#include <iostream>
#include "ExpressionsManager.h"
#include "FileManager.h"
#include "Exception.h"
#include "FileException.h"
#include "ExpressionValidator.h"
#include "RationalFractionOperation.h"
#include "Parser.h"

ExpressionsManager::ExpressionsManager(std::string pathToFile) : logFile_ ("log.txt") {
    fileManager_ = new FileManager(pathToFile);
}

bool ExpressionsManager::read(std::string fileName, std::string pathToFile) {
    bool isSuccessful = true;
    std::vector<std::string> expressions;
    RationalFractionOperation operation;
    Parser* parser = new Parser();
    fileManager_->setFile(fileName, pathToFile);
    try {
        fileManager_->validate();
    } catch (Exception& e) {
        isSuccessful = false;
        fileManager_->setFile(logFile_);
        fileManager_->writeLine("[File: " + fileName + "] " + e.execute());
    }

    if (isSuccessful) {
        expressions = fileManager_->read();
            for (int i = 0; i < expressions.size(); i++) {
                try {
                    operation = RationalFractionOperation(parser->parse(expressions[i]));
                    operations_.push_back(operation);
                } catch (Exception& e) {
                    fileManager_->setFile(logFile_);
                    fileManager_->writeLine("[File: " + fileName + "] " + "Expression '" + expressions[i] + "'. " + e.execute());
                }
            }
        fileManager_->setFile(logFile_);
        time_t now = time(0);
        fileManager_->writeLine(std::string(ctime(&now)) + "Data was read from file: " + fileName + ". ");
    }
    delete parser;
    return isSuccessful;
}

bool ExpressionsManager::write(std::string fileName) {
    fileManager_->setFile(fileName);
    for (int i = 0; i < results_.size(); i++) {
        fileManager_->writeLine(results_[i].toString());
    }
    fileManager_->setFile(logFile_);
    time_t now = time(0);
    fileManager_->writeLine(std::string(ctime(&now)) + "Result was written into file: " + fileName + ". ");
    return true;
}

bool ExpressionsManager::calculate() {
    for (int i = 0; i < operations_.size(); i++) {
        try {
            ExpressionValidator::validate(operations_[i]);
            results_.push_back(operations_[i].execute());
        } catch (Exception& e) {
            fileManager_->setFile(logFile_);
            fileManager_->writeLine("Expression '" + operations_[i].toString() + "': " + e.execute());
        }
    }
    return true;
}
