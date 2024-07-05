//
// Created by Bob on 5/27/2024.
//

#include "Car.h"

string Car::getMnufacturer() {
    return this -> manufacturer;
}

string Car::getModel() {
    return this -> model;
}

string Car::getColor() {
    return this -> color;
}

int Car::getYearOfFabrication() {
    return this -> yearOfFabrication;
}

Car::Car(string manufacturer, string model, int yearOfFabrication, string color) {
    this -> manufacturer = manufacturer;
    this -> model = model;
    this -> yearOfFabrication = yearOfFabrication;
    this -> color = color;
}
