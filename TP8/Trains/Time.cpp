#include <string>
#include "Time.h"

Time::Time(){
    hour_ = 0;
    minute_ = 0;
}

Time::Time(int hour, int minute){
    hour_ = hour;
    minute_ = minute;
}

Time::Time(const Time& sourse){
    hour_ = sourse.getHour();
    minute_ = sourse.getMinute();
}

int Time::getHour() const{
    return hour_;
}

void Time::setHour(int hour){
    hour_ = hour;
}

int Time::getMinute() const{
    return minute_;
}

void Time::setMinute(int minute){
    minute_ = minute;
}

int Time::compare(const Time& time){
    if (this->getHour() != time.getHour()){
        return this->getHour() - time.getHour();
    } else {
        return this->getMinute() - time.getMinute();
    }
}

bool Time::validate(){
    if (hour_ >= 0 && hour_ < 24 && minute_ >= 0 && minute_ < 60){
        return true;
    } else {
        return false;
    }
}

std::string Time::toString(){
    return std::to_string(this->getHour()) + ':' + std::to_string(this->getMinute());
}
