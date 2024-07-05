#include "domain.h"

School::School(string schoolName, float latitude, float longitude, string dateOfVisit)
{
    this->schoolName = schoolName;
    this->latitude = latitude;
    this->longitude = longitude;
    this->dateOfVisit = dateOfVisit;
}

string School::getSchoolName()
{
    return this->schoolName;
}
float School::getLatitude()
{
    return this->latitude;
}
float School::getLongitude()
{
    return this->longitude;
}
string School::getDateOfVisit()
{
    return this->dateOfVisit;
}
float School::getDistance()
{
    return this->eDistance;
}
void School::setDistance(float distance)
{
    this->eDistance = distance;
}