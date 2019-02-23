#include "Route.h"

Route::Route() {
    routeNumber_ = -1;
    driver_ = "";
    bus_ = make_pair(-1, "");
}

Route::Route(int routeNumber, string driver, pair<int, string> bus) {
    driver_ = driver;
    routeNumber_ = routeNumber;
    bus_ = bus;
}

Route::Route(const Route &source) {
    routeNumber_ = source.getRouteNumber();
    driver_ = source.getDriver();
    bus_ = source.getBus();
}

int Route::getRouteNumber() const {
    return routeNumber_;
}

string Route::getDriver() const {
    return driver_;
}

pair<int, string> Route::getBus() const {
    return bus_;
}

void Route::setRouteNumber(int routeNumber) {
    routeNumber_ = routeNumber;
}

void Route::setDriver(string driver) {
    driver_ = driver;
}

void Route::setBus(pair<int, string> bus) {
    bus_ = bus;
}


std::ostream& operator << (std::ostream &stream, const Route& student) {
    stream << student.getRouteNumber() << " " << student.getDriver() << " " <<
        student.getBus().first << " " << student.getBus().second << endl;
    return stream;
}

Route& Route::operator=(const Route& right) {
    if (this == &right) {
        return *this;
    }
    routeNumber_ = right.getRouteNumber();
    driver_ = right.getDriver();
    bus_ = right.getBus();
    return *this;
}