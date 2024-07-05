#pragma once
#include "car.h"
#include <vector>

class Service
{
private:
    vector<Car> carList;

public:
    void addCar(string bodyStyle, string engineType, int autonomy);
    vector<Car> getCarsWihMaxPrice(double maxPrice);
    void writeToFile(string fileName, vector<Car> cars);
    vector<Car> getCars();
    double getLastAddedCarPrice();
    void saveCarsWithPriceLowerThen(float price, string fileName);
    void generateEntries();
};