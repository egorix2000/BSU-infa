#include <string>
#include "Time.h"
#include "Train.h"
#include "Comparator.h"

bool Comparator::compareTrainsByTime(Train& train1, Train& train2){
    if (train1.getTimeOfDeparture().getHour() < train2.getTimeOfDeparture().getHour() ||
            (train1.getTimeOfDeparture().getHour() == train2.getTimeOfDeparture().getHour()
             && train1.getTimeOfDeparture().getMinute() < train2.getTimeOfDeparture().getMinute())){
        return true;
    } else {
        return false;
    }
}

bool Comparator::compareTrainsByDestination(Train& train1, Train& train2){
    if (train1.getDestination().compare(train2.getDestination()) < 0){
        return true;
    } else {
        return false;
    }
}
