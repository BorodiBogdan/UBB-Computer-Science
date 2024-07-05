#include "Car.h"
#include <vector>

class Service
{
private:
    vector<Car *> carList;
    int numberOfDoors;

public:
    void addCar(int numberOfDoors, string engineType, int autonomy);
    vector<Car *> getCars();
    void writeToFile(string fileName, vector<Car *> myCarList);
    Car *getLastCar();
    void addEntries();
    vector<Car *> getCarsWithMaxPrice(double price);
};