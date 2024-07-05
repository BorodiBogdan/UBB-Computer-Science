//
// Created by Bob on 5/27/2024.
//

#ifndef CARMANAGEMENT_SERVICE_H
#define CARMANAGEMENT_SERVICE_H
#include "Repository.h"

class Service {
private:
    Repository repo;
public:
    vector<Car> getCars();
    vector<Car> getCarsByManufacturer(string manufacturer);
    void addCar(Car a);
};


#endif //CARMANAGEMENT_SERVICE_H
