#include "repository.h"

class Controller
{
private:
    Repository schoolRepo;

public:
    vector<School> getSchoolsListSortedByName();
    /*
    we iterate trough all schools
    we compare the dates, and if the date < we mark the school as visited
    id the date is > and the school is not visited
    we mark it accordingly
    return -> list of non visited schools
    */
    vector<School> markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited(string date);
    /*
    we search for the school name and delete it if it is found
    param @schoolName - name of the deleted school
    */
    void deleteSchool(string schoolName);
    void addEntries();
};