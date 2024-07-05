//
// Created by Bob on 5/27/2024.
//

#ifndef CARMANAGEMENT_CAR_H
#define CARMANAGEMENT_CAR_H
#include <string>
using namespace std;

class Car {
private:
    string manufacturer, model;
    int yearOfFabrication;
    string color;
public:
    Car(string manufacturer, string model, int yearOfFabrication, string color);
    string getMnufacturer();
    string getModel();
    string getColor();
    int getYearOfFabrication();
};


#endif //CARMANAGEMENT_CAR_H
