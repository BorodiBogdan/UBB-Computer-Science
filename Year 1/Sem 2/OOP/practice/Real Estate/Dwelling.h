#include <string>
using namespace std;

class Dwelling
{
private:
    double price;
    bool isProfitable;

public:
    Dwelling(float price, bool isProfitable);
    double getPrice();
    bool getIsProfitable();
    string toString();
};