#include "HospitalDepartment.h"
#include <vector>

class Service
{
private:
    vector<HospitalDepartment *> departmentList;

public:
    void addDepartment(HospitalDepartment *department);
    vector<HospitalDepartment *> getAllDepartments();
    vector<HospitalDepartment *> getEfficientDepartments();
    void writeToFile(string fileName);
    void addEntries();
};