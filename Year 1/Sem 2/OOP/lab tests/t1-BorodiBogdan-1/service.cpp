#include "service.h"
#include <cmath>
#include <algorithm>

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

vector<School> Service::getSchools()
{
    return this->schoolRepo.getSchoolList();
}
void Service::addNewSchool(School schoolToBeAdded)
{
    try
    {
        this->schoolRepo.addNewSchool(schoolToBeAdded);
    }
    catch (const char *e)
    {
        throw(e);
    }
}

void Service::addEntries()
{
    School a = School("Avram_Iancu", 23.60, 46.77, "15.04.2022");
    School b = School("George_Cosbuc", 23.58, 46.77, "15.04.2022");
    School c = School("Alexandru_Vaida", 23.63, 46.77, "15.04.2022");
    School d = School("Romulus_Guga", 24.57, 46.53, "15.04.2022");
    School e = School("Colgeiul_Transilvania", 24.57, 46.54, "15.04.2022");

    this->schoolRepo.addNewSchool(a);
    this->schoolRepo.addNewSchool(b);
    this->schoolRepo.addNewSchool(c);
    this->schoolRepo.addNewSchool(d);
    this->schoolRepo.addNewSchool(e);
}

bool cmp1(School a, School b)
{
    return a.getSchoolName() < b.getSchoolName();
}
bool cmp2(School a, School b)
{
    return a.getDistance() < b.getDistance();
}

vector<School> Service::getSchoolsSortedByEuclideanSpaceAndName(float latitude, float longitude)
{
    vector<School> schoolList = this->schoolRepo.getSchoolList();

    for (int i = 0; i < schoolList.size(); ++i)
    {
        School x = schoolList[i];
        float x1 = x.getLongitude();
        float x2 = longitude;
        float y1 = x.getLatitude();
        float y2 = latitude;

        float Edistance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        schoolList[i].setDistance(Edistance);
    }

    sort(schoolList.begin(), schoolList.end(), cmp2);

    vector<School> retunrnVector;

    for (int i = 0; i <= min(2, schoolList.size() - 1); ++i)
        retunrnVector.push_back(schoolList[i]);

    sort(retunrnVector.begin(), retunrnVector.end(), cmp1);

    return retunrnVector;
}
