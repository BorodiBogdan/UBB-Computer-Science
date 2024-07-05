#include "Dwelling.h"

Dwelling::Dwelling(float price, bool isProfitable)
{
    this->price = price;
    this->isProfitable = isProfitable;
}

double Dwelling::getPrice()
{
    return this->price;
}

bool Dwelling::getIsProfitable()
{
    return this->isProfitable;
}

string Dwelling::toString()
{
    return "Price: " + to_string(this->price) + "\nIs profitable: " + to_string(this->isProfitable);
}
