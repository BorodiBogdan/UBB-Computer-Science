#pragma once
#include "engine.h"

class Car
{
private:
    string bodyStyle;
    Engine *engine;

public:
    Car(string bodyStyle, string engineType, int autonomy);
    double computePrice();
    string toString();
};
