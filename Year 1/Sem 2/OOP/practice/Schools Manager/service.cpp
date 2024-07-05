#include "service.h"
#include <algorithm>
#include <iostream>

bool cmp(School a, School b)
{
    return a.getName() > b.getName();
}
bool compareVisitDates(string visitDate1, string visitDate2)
{
    string year1 = visitDate1.substr(6, 4);
    string month1 = visitDate1.substr(3, 2);
    string day1 = visitDate1.substr(0, 2);
    string year2 = visitDate2.substr(6, 4);
    string month2 = visitDate2.substr(3, 2);
    string day2 = visitDate2.substr(0, 2);

    if (year1 < year2)
        return 1;

    if (year1 == year2 && month1 < month2)
        return 1;

    if (year1 == year2 && month1 == month2 && day1 < day2)
        return 1;

    return 0;
}
vector<School> Controller::getSchoolsListSortedByName()
{
    vector<School> newList = this->schoolRepo.getListOfSchools();

    sort(newList.begin(), newList.end(), cmp);

    return newList;
}

vector<School> Controller::markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited(string date)
{
    vector<School> listOfSchools;
    int pos = 0;

    for (auto school : schoolRepo.getListOfSchools())
    {
        if (compareVisitDates(school.getPlannedVisitDate(), date) == true)
        {
            school.setIsVisited(true);
            this->schoolRepo.setIsVisited(pos);
        }
        else if (compareVisitDates(school.getPlannedVisitDate(), date) == false && school.getIsVisited() == false)
        {
            listOfSchools.push_back(school);
        }
        ++pos;
    }
    return listOfSchools;
}

void Controller::deleteSchool(string schoolName)
{
    try
    {
        this->schoolRepo.deleteSchoolRepo(schoolName);
    }
    catch (const char *e)
    {
        throw(e);
    }
}

void Controller::addEntries()
{
    string schoolName[] = {
        "Avram_Iancu",
        "George_Cosbuc",
        "Alexandru_Vaida",
        "Kante_Cotirla",
        "Borodi Bogdan",
    };

    string coordinates[] = {
        "46.77 12,12",
        "30,12 8,13",
        "10,90 89,99",
        "45,45 56,65",
        "12,12 12,98"};

    string dates[] = {
        "15.04.2022",
        "18.04.2022",
        "23.04.2022",
        "04.05.2022",
        "03.05.2022"};

    for (int i = 0; i < 5; ++i)
    {
        School schoolToBeAdded = School(schoolName[i], coordinates[i], dates[i], false);

        this->schoolRepo.addSchoolRepo(schoolToBeAdded);
    }
}
