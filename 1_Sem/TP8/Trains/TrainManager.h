#pragma once
#ifndef TRAINMANAGER_H_INCLUDED
#define TRAINMANAGER_H_INCLUDED

#include <vector>
#include "Train.h"
#include "Time.h"

class TrainManager {
    public:
        void sortByTimeOfDeparture();
        void sortByDestination();
        std::vector<Train> getAllTrains();
        std::vector<Train> getTrainsByDestination(std::string destination);
        std::vector<Train> getTrainsLaterThanTime(const Time& time);
        void addTrain(const Train& train);
        void resetTrains();
    private:
        std::vector<Train> trains_;
};

#endif // TRAINMANAGER_H_INCLUDED
