#include <iostream>
#include <fstream>
#include "Train.h"
#include "TrainManager.h"
#include "FileLib.h"

using namespace std;

void printMenu(){
    cout << "Enter" << endl;
    cout << "1 to load data from file" << endl;
    cout << "2 to print info about all trains" << endl;
    cout << "3 to sort trains by time of departure" << endl;
    cout << "4 to sort trains by destination" << endl;
    cout << "5 to print info about all trains with entererd destination" << endl;
    cout << "6 to print info about all trains which departs later than entered time of departure destination" << endl;
    cout << "0 to exit" << endl;
}

void print(TrainManager& trainManager){
    vector<Train> trains = trainManager.getAllTrains();
    if (trains.size() > 0){
        for (int i = 0; i < trains.size(); i++){
            cout << trains[i];
        }
    } else {
        cout << "No trains found" << endl;
    }
}

void sortByTime(TrainManager& trainManager){
    trainManager.sortByTimeOfDeparture();
}

void sortByDestination(TrainManager& trainManager){
    trainManager.sortByDestination();
}

void printAfterTime(TrainManager& trainManager){
    int hour;
    int minute;
    Time time;
    cout << "Enter time (hour and minute): ";
    cin >> hour >> minute;
    time = Time(hour, minute);
    if (time.validate()){
        vector<Train> trains = trainManager.getTrainsLaterThanTime(time);
        if (trains.size() > 0){
            for (int i = 0; i < trains.size(); i++){
                cout << trains[i];
            }
        } else {
            cout << "No trains found" << endl;
        }
    } else {
        cout << "Incorrect time" << endl;
    }
}

void printWithDestiny(TrainManager& trainManager){
    string destination;
    cout << "Enter destination: ";
    cin >> destination;
    vector<Train> trains = trainManager.getTrainsByDestination(destination);
    if (trains.size() > 0){
        for (int i = 0; i < trains.size(); i++){
            cout << trains[i];
        }
    } else {
        cout << "No trains found" << endl;
    }
}

void load(TrainManager& trainManager){
    trainManager.resetTrains();
    ifstream fin;
    string file;
    Train train;
    cout << "Enter full path to file and filename with extension: "; // example: /Users/apple/Documents/Project/input.txt
    cin >> file;
    fin.open(file);
    try {
        validateFile(fin);
        while (fin >> train){
            trainManager.addTrain(train);
        }
    } catch (string e) {
        cout << e << endl;
    }
    fin.close();
}

void exit(){
    cout << "Exit" << endl;
}

int main()
{
    TrainManager trainManager;
    printMenu();
    int selectedItem = 1;

    while (selectedItem != 0){
        cin >> selectedItem;
        switch (selectedItem){
            case 0:
                exit();
                break;
            case 1:
                load(trainManager);
                break;
            case 2:
                print(trainManager);
                break;
            case 3:
                sortByTime(trainManager);
                break;
            case 4:
                sortByDestination(trainManager);
                break;
            case 5:
                printAfterTime(trainManager);
                break;
            case 6:
                printWithDestiny(trainManager);
                break;
            default:
                break;
        }
    }
    return 0;
}
