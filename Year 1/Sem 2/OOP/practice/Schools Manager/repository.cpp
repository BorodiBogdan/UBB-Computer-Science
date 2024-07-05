#include "repository.h"

void Repository::addSchoolRepo(School childToBeAdded)
{
    this->schoolList.push_back(childToBeAdded);
}

void Repository::deleteSchoolRepo(string schoolToBeDeletedName)
{
    vector<School>::iterator it;

    for (it = this->schoolList.begin(); it != schoolList.end(); ++it)
        if (it->getName() == schoolToBeDeletedName)
        {
            this->schoolList.erase(it);
            return;
        }

    throw("The school is not in the list!!!");
}

vector<School> Repository::getListOfSchools()
{
    return this->schoolList;
}
void Repository::setIsVisited(int pos)
{
    this->schoolList[pos].setIsVisited(true);
}
