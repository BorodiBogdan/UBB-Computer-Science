#include "Service.h"
#include <fstream>
#include <algorithm>

void Service::addCar(int numberOfDoors, string engineType, int autonomy)
{
    Engine *newEngine = nullptr;

    if (engineType == "Electric")
    {
        newEngine = new ElectricEngine(3000, autonomy);
    }
    else
    {
        newEngine = new TurboEngine(3000);
    }
    this->carList.push_back(new Car(numberOfDoors, newEngine));
}

vector<Car *> Service::getCars()
{
    return this->carList;
}
bool cmp(Car *a, Car *b)
{
    return a->getNumberOfDoors() < b->getNumberOfDoors();
}

void Service::writeToFile(string fileName, vector<Car *> myCarList)
{
    if (myCarList.size() == 0)
        return;

    sort(myCarList.begin(), myCarList.end(), cmp);
    int nr = myCarList[0]->getNumberOfDoors();
    ofstream fout(fileName);

    fout << "Group 1:\n\n";

    for (auto car : myCarList)
    {
        if (nr != car->getNumberOfDoors())
        {
            nr = car->getNumberOfDoors();
            fout << "\nGroup 2:\n\n";
        }

        fout << car->toString() << "\n________________\n";
    }
}

Car *Service::getLastCar()
{
    return this->carList.back();
}

void Service::addEntries()
{
    this->addCar(4, "Electric", 20);
    this->addCar(2, "Electric", 1900);
    this->addCar(4, "Turbo", 0);
    this->addCar(2, "Turbo", 0);
}

vector<Car *> Service::getCarsWithMaxPrice(double price)
{
    vector<Car *> searchedCars;

    for (auto car : this->getCars())
        if (car->computePrice() <= price)
            searchedCars.push_back(car);

    return searchedCars;
}
