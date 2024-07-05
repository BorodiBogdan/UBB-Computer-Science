#pragma once
#include <string>
using namespace std;

class Engine
{
protected:
    int basePrice;

public:
    virtual double getPrice() = 0;
    virtual string toString() = 0;
};

class ElectricEngine : public Engine
{
private:
    int autonomy;

public:
    ElectricEngine(int autonomy);
    double getPrice();
    string toString();
};
class TurboEngine : public Engine
{
public:
    TurboEngine();
    double getPrice();
    string toString();
};