#include <vector>
#include <algorithm>
#include "TrainManager.h"
#include "Train.h"
#include "Time.h"
#include "Comparator.h"

void TrainManager::sortByTimeOfDeparture(){
    std::sort(trains_.begin(), trains_.end(), &Comparator::compareTrainsByTime);
}

void TrainManager::sortByDestination(){
    std::sort(trains_.begin(), trains_.end(), &Comparator::compareTrainsByDestination);
}

std::vector<Train> TrainManager::getTrainsByDestination(std::string destination){
    std::vector<Train> trainsWithDestination;
    for (int i = 0; i < trains_.size(); i++){
        if (trains_[i].getDestination() == destination){
            trainsWithDestination.push_back(trains_[i]);
        }
    }
    return trainsWithDestination;
}

std::vector<Train> TrainManager::getTrainsLaterThanTime(const Time& time){
    std::vector<Train> trainsLaterThanTime;
    for (int i = 0; i < trains_.size(); i++){
        if (trains_[i].getTimeOfDeparture().compare(time) > 0){
            trainsLaterThanTime.push_back(trains_[i]);
        }
    }
    return trainsLaterThanTime;
}

void TrainManager::addTrain(const Train& train){
    trains_.push_back(Train(train));
}

std::vector<Train> TrainManager::getAllTrains(){
    return trains_;
}

void TrainManager::resetTrains(){
    trains_.clear();
}
