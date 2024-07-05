#include "Service.h"
#include "fstream"
#include <algorithm>

void Service::addDepartment(HospitalDepartment *department)
{
    this->departmentList.push_back(department);
}

vector<HospitalDepartment *> Service::getAllDepartments()
{
    return this->departmentList;
}

vector<HospitalDepartment *> Service::getEfficientDepartments()
{
    vector<HospitalDepartment *> searchedDepartments;

    for (auto department : this->departmentList)
        if (department->isEfficient())
            searchedDepartments.push_back(department);

    return searchedDepartments;
}

bool cmp(HospitalDepartment *a, HospitalDepartment *b)
{
    return a->getName() < b->getName();
}

void Service::writeToFile(string fileName)
{
    ofstream fout(fileName);

    vector<HospitalDepartment *> v = this->departmentList;

    sort(v.begin(), v.end(), cmp);

    for (auto department : v)
        fout << department->toString() << "\n_______________________\n";

    fout.close();
}

void Service::addEntries()
{
    this->addDepartment(new Surgery("Mihai", 20, 40));
    this->addDepartment(new Surgery("Andrei", 25, 40));
    this->addDepartment(new NeonatalUnits("Costan", 25, 40, 20, 8.6));
    this->addDepartment(new NeonatalUnits("Liviu", 25, 40, 20, 8.2));
}
