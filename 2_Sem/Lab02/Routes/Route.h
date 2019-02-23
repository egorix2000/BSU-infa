#ifndef LAB_ROUTE_H
#define LAB_ROUTE_H

#include <string>
#include <iostream>

using namespace std;

class Route {
private:
    int routeNumber_;
    string driver_;
    pair<int, string> bus_; // number and brand
public:
    Route();
    Route(int routeNumber, string driver, pair<int, string> bus);
    Route(const Route& source);
    int getRouteNumber() const;
    string getDriver() const;
    pair<int, string> getBus() const;
    void setRouteNumber(int routeNumber);
    void setDriver(string driver);
    void setBus(pair<int, string> bus);
    friend std::ostream& operator << (std::ostream &stream, const Route& route);
    Route& operator=(const Route& right);
};


#endif //LAB_ROUTE_H
