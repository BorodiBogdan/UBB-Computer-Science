#include "Engine.h"

ElectricEngine::ElectricEngine(double basePrice, int autonomy)
{
    this->basePrice = basePrice;
    this->autonomy = autonomy;
}

double ElectricEngine::getPrice()
{
    return this->basePrice + 0.01 * autonomy;
}

string ElectricEngine::toString()
{
    return "Type: Electric\nBase price: " + to_string(this->basePrice) + "\nEngine price: " + to_string(this->getPrice()) + "\nAutonomy: " + to_string(this->autonomy);
}

TurboEngine::TurboEngine(double basePrice)
{
    this->basePrice = basePrice;
}

double TurboEngine::getPrice()
{
    return this->basePrice + 100;
}

string TurboEngine::toString()
{
    return "Type: Turbo\nBase price: " + to_string(this->basePrice) + "\nEngine price: " + to_string(this->getPrice());
}

double Engine::getPrice()
{
    return this->basePrice;
}
