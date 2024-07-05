#include "HospitalDepartment.h"

Surgery::Surgery(string name, int numberOfDoctors, int numberOfPatients)
{
    this->hospitalName = name;
    this->numberOfDoctors = numberOfDoctors;
    this->numberOfPatients = numberOfPatients;
}

bool Surgery::isEfficient()
{
    return this->numberOfPatients / this->numberOfDoctors >= 2;
}

string Surgery::toString()
{
    string r = "Type: surgery\nHospital name: " + this->hospitalName + "\nNumber of doctors: " + to_string(this->numberOfDoctors);
    r += "\nNumber of patients: " + to_string(this->numberOfPatients);

    return r;
}

NeonatalUnits::NeonatalUnits(string name, int nrOfDocs, int numberOfMothers, int numberOfNewBorns, double averageGrade)
{
    this->averageGrade = averageGrade;
    this->hospitalName = name;
    this->numberOfDoctors = nrOfDocs;
    this->numberOfMothers = numberOfMothers;
    this->numberOfNewBorns = numberOfNewBorns;
}

bool NeonatalUnits::isEfficient()
{
    return this->averageGrade > 8.5 && this->numberOfNewBorns >= this->numberOfMothers;
}

string NeonatalUnits::toString()
{
    string r = "Type: NeoNatal Units\nHospital name: " + this->hospitalName + "\nNumber of doctors: " + to_string(this->numberOfDoctors);
    r += "\nNumber of mothers: " + to_string(this->numberOfMothers) + "\nNumber of new borns: " + to_string(this->numberOfNewBorns);
    r += "\nAverage grade: " + to_string(this->averageGrade);

    return r;
}

string HospitalDepartment::getName()
{
    return this->hospitalName;
}
