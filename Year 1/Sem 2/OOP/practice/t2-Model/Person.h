#pragma once
#include "BP.h"
#include "BMI.h"
#include <vector>

class Person
{
private:
    string name;
    vector<MedicalAnalysis *> medicalAnalysisList;

public:
    void addAnalysis(MedicalAnalysis *analysis);
    vector<MedicalAnalysis *> getAllAnalysisByMonth(int month);
    vector<MedicalAnalysis *> getAllAnalysis();
    bool isIll(int month);
    vector<MedicalAnalysis *> getAnalysisBetweenDates(string date1, string date2);
    void writeToFile(string fileName, string date1, string date2);
};