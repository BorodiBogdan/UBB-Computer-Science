#include "service.h"
#include <fstream>
#include <algorithm>

void Service::addCar(string bodyStyle, string engineType, int autonomy)
{
    Car newCar = Car(bodyStyle, engineType, autonomy);
    this->carList.push_back(newCar);
}
bool cmp(Car a, Car b)
{
    if (a.computePrice() > b.computePrice())
        return 0;
    return 1;
}
vector<Car> Service::getCarsWihMaxPrice(double maxPrice)
{
    return vector<Car>();
}

void Service::writeToFile(string fileName, vector<Car> cars)
{
    ofstream fout(fileName);
    sort(cars.begin(), cars.end(), cmp);
    for (auto car : cars)
        fout << car.toString() << "\n_________________________________________\n";
    ;

    fout.close();
}

vector<Car> Service::getCars()
{
    return this->carList;
}

double Service::getLastAddedCarPrice()
{
    return this->carList.back().computePrice();
}

void Service::saveCarsWithPriceLowerThen(float price, string fileName)
{
    vector<Car> saveCars;

    for (auto car : this->carList)
        if (car.computePrice() < price)
            saveCars.push_back(car);

    this->writeToFile(fileName, saveCars);
}

void Service::generateEntries()
{
    this->addCar("Sedan", "Electric", 200);
    this->addCar("Convertible", "Electric", 210);
    this->addCar("Convertible", "Turbo", 0);
}
