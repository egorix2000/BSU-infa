#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

#include "Route.h"
#include "FileLib.h"

using namespace std;

Route& parseRouteString(string line, Route& route) {
    int routeNumber;
    string driver;
    int busNumber;
    string busBrand;

    stringstream ss;
    ss << line;
    ss >> routeNumber >> driver >> busNumber >> busBrand;
    route.setRouteNumber(routeNumber);
    route.setDriver(driver);
    route.setBus(make_pair(busNumber, busBrand));
    return route;
}

map<string, Route>& changeDriver(map<string, Route>& routes) {
    string oldDriver;
    string newDriver;
    cout << "Change driver. Enter driver name you want to replace: ";
    cin >> oldDriver;
    cout << "Enter new driver name: ";
    cin >> newDriver;

    routes[oldDriver].setDriver(newDriver);

    cout << "Done! Route with driver '" << oldDriver << "' has been modified." << endl;
    return routes;
}

map<string, Route>& findByRouteNumber(map<string, Route>& routesMap, map<string, Route>& foundRoutesByRouteNumber) {
    int routeNumber;
    cout << "Enter route number: ";
    cin >> routeNumber;
    copy_if(routesMap.begin(), routesMap.end(), inserter(foundRoutesByRouteNumber, foundRoutesByRouteNumber.begin()),
            [routeNumber](const pair<string, Route>& routeP) {
                return routeP.second.getRouteNumber() == routeNumber;
            });
    return foundRoutesByRouteNumber;
}

Route& findByDriver(map<string, Route>& routesMap) {
    string driver;
    cout << "Enter driver name: ";
    cin >> driver;
    return routesMap[driver];
}

vector<Route>& showRoutes(vector<Route>& routes) {
    for (int i = 0; i < routes.size(); i++) {
        cout << routes[i];
    }
    return routes;
}

map<string, Route>& showRoutesMap(map<string, Route>& routes) {
    for (map<string, Route>::iterator it = routes.begin(); it != routes.end(); it++) {
        cout << (*it).second;
    }
    return routes;
}

int main()
{
    vector<Route> routes;
    map<string, Route> routesMap;
    map<string, Route> foundRoutesByRouteNumber;

    Route route;
    string error;
    string line;
    ifstream fin;

    fin.open("input.txt");

    if(validateFile(fin, error)){

        while (getline(fin, line)){
            parseRouteString(line, route);
            routes.push_back(route);
        }

        //sort by routeNumber ASC
        sort(routes.begin(), routes.end(), [](Route& route1, Route& route2) {
            return route1.getRouteNumber() < route2.getRouteNumber();
        });
        cout << "Sorted by route number routes:" << endl;
        showRoutes(routes);

        //generate map
        for (int i = 0; i < routes.size(); i++) {
            routesMap[routes[i].getDriver()] = routes[i];
        }

        //find all routes by entered routeNumber
        findByRouteNumber(routesMap, foundRoutesByRouteNumber);
        cout << "Found routes:" << endl;
        showRoutesMap(foundRoutesByRouteNumber);

        //change route driver
        changeDriver(routesMap);
        cout << "New routes:" << endl;
        showRoutesMap(routesMap);

        //find route by entered driver
        route = findByDriver(routesMap);
        cout << "Found route: " << route;

        //find routeNumber with the most buses
        cout << "Route number with the most buses: ";
        cout << (*max_element(routesMap.begin(), routesMap.end(), [routesMap](const pair<string, Route>& routeP1, const pair<string, Route>& routeP2) {
            return count_if(routesMap.begin(), routesMap.end(), [routeP1](const pair<string, Route>& routeP){
                return routeP.second.getRouteNumber() == routeP1.second.getRouteNumber();
            }) < count_if(routesMap.begin(), routesMap.end(), [routeP2](const pair<string, Route>& routeP){
                return routeP.second.getRouteNumber() == routeP2.second.getRouteNumber();
            });
        })).second.getRouteNumber();
    } else {
        cout << error << endl;
    }

    fin.close();
    return 0;
}