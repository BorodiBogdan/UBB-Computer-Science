#include "repository.h"

class Service
{
private:
    Repository schoolRepo;

public:
    vector<School> getSchools();

    /*
    param @schoolToBeAdded - School
    we add a new school to the list
    if the school is already in the list  we trhow an errror
    */
    void addNewSchool(School schoolToBeAdded);
    void addEntries();
    /*
    param @latitude:
    param @longitude

    we sort the array of schools by the distance from a school to the latitude and longitute provided by the user
    we select the first 3 schools from the sorting
    we sort these schools again by name
    we return the sorted vector
    */
    vector<School> getSchoolsSortedByEuclideanSpaceAndName(float latitude, float longitude);
};