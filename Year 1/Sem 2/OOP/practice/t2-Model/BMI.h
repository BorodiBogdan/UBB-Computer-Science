#pragma once
#include "MedicalAnalysis.h"

class BMI : public MedicalAnalysis
{
private:
    double value;

public:
    BMI(string date, int value);
    bool isResultOk();
    string toString();
    friend ostream &operator<<(ostream &out, const BMI &med);
};