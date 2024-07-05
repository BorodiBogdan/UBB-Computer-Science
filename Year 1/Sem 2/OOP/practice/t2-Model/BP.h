#pragma once
#include "MedicalAnalysis.h"

class BP : public MedicalAnalysis
{
private:
    int systolicValue, diastolicValue;

public:
    BP(int systolic, int diastolic, string date);
    bool isResultOk();
    string toString();
    friend ostream &operator<<(ostream &out, const BP &med);
};
