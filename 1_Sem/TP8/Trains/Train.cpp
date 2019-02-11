#include <string>
#include <iostream>
#include <fstream>
#include "Train.h"
#include "Time.h"

Train::Train(){
    destination_ = "";
    trainNumber_ = "";
    timeOfDeparture_ = Time();
}

Train::Train(std::string destination, std::string trainNumber, Time& timeOfDeparture){
    destination_ = destination;
    trainNumber_ = trainNumber;
    timeOfDeparture_ = Time(timeOfDeparture);
}

Train::Train(const Train& train){
    destination_ = train.getDestination();
    trainNumber_ = train.getTrainNumber();
    timeOfDeparture_ = Time(train.getTimeOfDeparture());
}

std::string Train::getDestination() const{
    return destination_;
}

std::string Train::getTrainNumber() const{
    return trainNumber_;
}

Time Train::getTimeOfDeparture() const{
    return timeOfDeparture_;
}

void Train::setDestination(std::string destination){
    destination_ = destination;
}

void Train::setTrainNumber(std::string trainNumber){
    trainNumber_ = trainNumber;
}

void Train::setTimeOfDeparture(Time& timeOfDeparture){
    timeOfDeparture_ = Time(timeOfDeparture);
}

std::ostream& operator<<(std::ostream &os, const Train& train) {
    os << train.getDestination() << ' ' << train.getTrainNumber() << ' ' << train.getTimeOfDeparture().toString() << '\n';
	return os;
}

std::ifstream& operator >> (std::ifstream &stream, Train& train) {
    std::string destination;
    std::string trainNumber;
    std::string hour;
    std::string minute;
    Time time;
	stream >> destination;
	stream >> trainNumber;
	stream >> hour >> minute;
	train.setDestination(destination);
	train.setTrainNumber(trainNumber);
	time = Time(atoi(hour.c_str()), atoi(minute.c_str()));
	train.setTimeOfDeparture(time);
	return stream;
}
