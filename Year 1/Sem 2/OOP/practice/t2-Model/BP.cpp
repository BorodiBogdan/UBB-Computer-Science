#include "BP.h"

BP::BP(int systolic, int diastolic, string date)
{
    this->systolicValue = systolic;
    this->diastolicValue = diastolic;
    this->date = date;
}

bool BP::isResultOk()
{
    return this->diastolicValue >= 60 && this->diastolicValue <= 79 && this->systolicValue >= 90 && this->systolicValue <= 119;
}

string BP::toString()
{
    return this->date + " | " + to_string(this->systolicValue) + " | " + to_string(this->diastolicValue) + " | " + "BP";
}
