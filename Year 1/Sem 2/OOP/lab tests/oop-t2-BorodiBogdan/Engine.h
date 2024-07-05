#include <string>
using namespace std;

class Engine
{
protected:
    double basePrice;

public:
    virtual double getPrice();
    virtual string toString() = 0;
};

class ElectricEngine : public Engine
{
private:
    int autonomy;

public:
    ElectricEngine(double basePrice, int autonomy);
    double getPrice();
    string toString();
};

class TurboEngine : public Engine
{
public:
    TurboEngine(double basePrice);
    double getPrice();
    string toString();
};