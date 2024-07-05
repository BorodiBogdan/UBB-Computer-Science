#include "engine.h"

ElectricEngine::ElectricEngine(int autonomy)
{
    this->autonomy = autonomy;
    this->basePrice = 3000;
}

double ElectricEngine::getPrice()
{
    return this->basePrice + this->autonomy * 0.01;
}

string ElectricEngine::toString()
{
    return "Type: Electric\nBase price: " + to_string(this->basePrice) + "\nAutonomy: " + to_string(this->autonomy);
}

TurboEngine::TurboEngine()
{
    this->basePrice = 3000;
}

double TurboEngine::getPrice()
{
    return this->basePrice + 100;
}

string TurboEngine::toString()
{
    return "Type: Turbo\nBase price: " + to_string(this->basePrice);
}
