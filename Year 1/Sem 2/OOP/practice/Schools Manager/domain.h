#include <string>
using namespace std;

class School
{
private:
    string name, address, plannedVisitDate;
    bool isVisited;

public:
    School(string name, string adress, string plannedVisitDate, bool isVisited);
    string getName();
    string getAddress();
    string getPlannedVisitDate();
    bool getIsVisited();
    void setIsVisited(bool value);
};