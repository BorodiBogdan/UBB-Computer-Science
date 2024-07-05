//
// Created by Bob on 5/27/2024.
//

#ifndef CARMANAGEMENT_REPOSITORY_H
#define CARMANAGEMENT_REPOSITORY_H
#include "Car.h"
#include <vector>

class Repository {
private:
    vector<Car>carList;
public:
    Repository();
    vector<Car>getCars();
    void readFromFile();
    void addCar(Car a);
};


#endif //CARMANAGEMENT_REPOSITORY_H
