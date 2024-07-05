#include "Engine.h"

class Car
{
private:
    int numberOfDoors;
    Engine *engine;

public:
    Car(int numberOfDoors, Engine *engine);
    double computePrice();
    int getNumberOfDoors();
    string toString();
};