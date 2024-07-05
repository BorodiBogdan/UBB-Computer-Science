#include <string>
#pragma once
using namespace std;

class MedicalAnalysis
{
protected:
    string date;

public:
    virtual bool isResultOk() = 0;
    virtual string toString();
};