#include "domain.h"

School::School(string name, string adress, string plannedVisitDate, bool isVisited)
{
    this->name = name;
    this->address = adress;
    this->plannedVisitDate = plannedVisitDate;
    this->isVisited = isVisited;
}

string School::getName()
{
    return this->name;
}
string School::getAddress()
{
    return this->address;
}
string School::getPlannedVisitDate()
{
    return this->plannedVisitDate;
}
bool School::getIsVisited()
{
    return this->isVisited;
}
void School::setIsVisited(bool value)
{
    this->isVisited = value;
}