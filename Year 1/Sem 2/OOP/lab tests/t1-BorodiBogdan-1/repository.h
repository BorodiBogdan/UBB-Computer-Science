#include "domain.h"
#include <vector>

class Repository
{
private:
    vector<School> schoolList;

public:
    vector<School> getSchoolList();
    /*
    param @schoolToBeAdded - School
    we add a new school to the list
    if the school is already in the list  we trhow an errror
    */
    void addNewSchool(School schoolToBeAdded);
};