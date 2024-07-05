#include "repository.h"

vector<School> Repository::getSchoolList()
{
    return this->schoolList;
}
void Repository::addNewSchool(School schoolToBeAdded)
{
    for (auto school : this->schoolList)
        if (school.getLatitude() == schoolToBeAdded.getLatitude() && school.getLongitude() == schoolToBeAdded.getLongitude() && school.getSchoolName() == schoolToBeAdded.getSchoolName())
            throw("School already in!!");

    this->schoolList.push_back(schoolToBeAdded);
}