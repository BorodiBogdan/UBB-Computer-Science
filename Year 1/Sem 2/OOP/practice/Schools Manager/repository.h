#include "domain.h"
#include <vector>

class Repository
{
private:
    vector<School> schoolList;

public:
    void addSchoolRepo(School schoolToBeAdded);
    void deleteSchoolRepo(string schoolToBeDeletedName);
    vector<School> getListOfSchools();
    void setIsVisited(int pos);
};