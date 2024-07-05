//
// Created by Bob on 5/27/2024.
//

#include "Service.h"
#include <algorithm>
#include <QDebug>

vector<Car> Service::getCars() {
    vector<Car> carList = this -> repo.getCars();

    sort(carList.begin(), carList.end(), [](Car a, Car b)->bool{
        return a.getMnufacturer() < b.getMnufacturer();
    });

    return carList;
}

vector<Car> Service::getCarsByManufacturer(string manufacturer) {
    /*
     *@manufacturer -> manufacturer name
     * return vector<Car> -> list of all cars from a manufacturer
     * we iterate through all cars and if the manufacturer is good we add it into the list
     */
    vector<Car> carList;

    for(auto car : this -> repo.getCars()) {
        if (car.getMnufacturer() == manufacturer)
            carList.push_back(car);
    }

    return carList;
}

void Service::addCar(Car a) {
    this -> repo.addCar(a);
}
