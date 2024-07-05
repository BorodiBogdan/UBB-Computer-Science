using namespace std;
#include <string>

class School
{
private:
    string schoolName;
    float latitude, longitude;
    string dateOfVisit;
    float eDistance;

public:
    School(string schoolName, float latitude, float longitude, string dateOfVisit);
    string getSchoolName();
    float getLatitude();
    float getLongitude();
    string getDateOfVisit();
    float getDistance();
    void setDistance(float distance);
};