#pragma once
#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "Time.h"

class Train {
    public:
        Train();
        Train(std::string destination_, std::string trainNumber_, Time& timeOfDeparture_);
        Train(const Train& train);
        std::string getDestination() const;
        std::string getTrainNumber() const;
        Time getTimeOfDeparture() const;
        void setDestination(std::string destination);
        void setTrainNumber(std::string trainNumber);
        void setTimeOfDeparture(Time& timeOfDeparture);
        friend std::ostream& operator<<(std::ostream &os, const Train& train);
        friend std::ifstream& operator >> (std::ifstream &stream, Train& train);
    private:
        std::string destination_;
        std::string trainNumber_;
        Time timeOfDeparture_;

};

#endif // TRAIN_H_INCLUDED
