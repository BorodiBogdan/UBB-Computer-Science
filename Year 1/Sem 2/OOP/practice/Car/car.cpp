#include "car.h"

Car::Car(string bodyStyle, string engineType, int autonomy)
{
    if (engineType == "Electric")
    {
        Engine *newEngine = new ElectricEngine(autonomy);
        this->engine = newEngine;
    }
    else
    {
        Engine *newEngine = new TurboEngine;
        this->engine = newEngine;
    }
    this->bodyStyle = bodyStyle;
}

double Car::computePrice()
{
    if (bodyStyle == "Sedan")
        return 8000 + engine->getPrice();
    else if (bodyStyle == "Convertible")
        return 1000 + engine->getPrice();

    return 0;
}

string Car::toString()
{
    return this->engine->toString() + "\nBody style: " + this->bodyStyle + "\nPrice: " + to_string(this->computePrice());
}
