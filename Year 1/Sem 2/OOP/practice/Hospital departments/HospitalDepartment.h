#pragma once
using namespace std;
#include <string>

class HospitalDepartment
{
protected:
    string hospitalName;
    int numberOfDoctors;

public:
    virtual string getName();
    virtual bool isEfficient() = 0;
    virtual string toString() = 0;
};

class NeonatalUnits : public HospitalDepartment
{
private:
    int numberOfMothers;
    int numberOfNewBorns;

public:
    NeonatalUnits(string name, int nrOfDocs, int numberOfMothers, int numberOfNewBorns, double averageGrade);
    double averageGrade;
    bool isEfficient();
    string toString();
};

class Surgery : public HospitalDepartment
{
private:
    int numberOfPatients;

public:
    Surgery(string name, int numberOfDoctors, int numberOfPatients);
    bool isEfficient();
    string toString();
};