#include "Person.h"
#include <fstream>
#include <iostream>

void Person::addAnalysis(MedicalAnalysis *analysis)
{
    this->medicalAnalysisList.push_back(analysis);
}

vector<MedicalAnalysis *> Person::getAllAnalysisByMonth(int month)
{
    vector<MedicalAnalysis *> searchedAnalysis;
    for (auto analysis : this->medicalAnalysisList)
    {
        int analysisMonth = stoi(analysis->toString().substr(5, 2));
        if (analysisMonth == month)
            searchedAnalysis.push_back(analysis);
    }
    return searchedAnalysis;
}

vector<MedicalAnalysis *> Person::getAllAnalysis()
{
    return this->medicalAnalysisList;
}

bool Person::isIll(int month)
{
    for (auto analysis : this->medicalAnalysisList)
    {
        int analysisMonth = stoi(analysis->toString().substr(5, 2));
        int year = stoi(analysis->toString().substr(0, 4));

        if (month == analysisMonth && analysis->isResultOk() == true && year == 2024)
            return false;
    }
    return true;
}

vector<MedicalAnalysis *> Person::getAnalysisBetweenDates(string date1, string date2)
{
    vector<MedicalAnalysis *> searchedAnalysis;

    if (date1 > date2)
        swap(date1, date2);

    for (auto analysis : this->medicalAnalysisList)
    {

        if (analysis->toString().substr(0, 10) <= date2 && analysis->toString().substr(0, 10) >= date1)
            searchedAnalysis.push_back(analysis);
    }

    return searchedAnalysis;
}

void Person::writeToFile(string fileName, string date1, string date2)
{
    ofstream fout(fileName);

    vector<MedicalAnalysis *> v = getAnalysisBetweenDates(date1, date2);

    for (auto x : v)
    {
        cout << fileName << " " << x->toString() << "\n";
        fout << x->toString() << '\n';
    }
}
