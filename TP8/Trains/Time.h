#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <string>

class Time {
    private:
        int hour_;
        int minute_;
    public:
        Time();
        Time(int hour, int minute);
        Time(const Time& sourse);
        int getHour() const;
        void setHour(int hour);
        int getMinute() const;
        void setMinute(int minute);
        int compare(const Time& time);
        std::string toString();
        bool validate();
};

#endif // TIME_H_INCLUDED
