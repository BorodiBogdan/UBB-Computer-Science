#include "Car.h"

Car::Car(int numberOfDoors, Engine *engine)
{
    this->numberOfDoors = numberOfDoors;
    this->engine = engine;
}

double Car::computePrice()
{
    if (this->numberOfDoors == 2)
        return this->engine->getPrice() + 7000;
    else
        return this->engine->getPrice() + 8500;
}

int Car::getNumberOfDoors()
{
    return this->numberOfDoors;
}

string Car::toString()
{
    return this->engine->toString() + "\nNumber of doors: " + to_string(this->numberOfDoors) + "\nTotal price: " + to_string(this->computePrice());
}
