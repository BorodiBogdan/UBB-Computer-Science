#include "BMI.h"

BMI::BMI(string date, int value)
{
    this->date = date;
    this->value = value;
}

bool BMI::isResultOk()
{
    return this->value >= 18.5 && this->value <= 25;
}

string BMI::toString()
{
    return this->date + " | " + to_string(this->value) + "| BMI";
}
