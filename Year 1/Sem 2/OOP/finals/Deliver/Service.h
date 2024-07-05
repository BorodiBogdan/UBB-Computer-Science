//
// Created by Bob on 6/26/2024.
//

#ifndef INC_1ST_QT_PROJECT_SERVICE_H
#define INC_1ST_QT_PROJECT_SERVICE_H
#include "Repository.h"
#include "Observer.h"

class Service : public Subject{
private:
    Repository repo;
public:
    Service() = default;
    vector<Package> &get_packages(){return this -> repo.get_packages();}
    vector<Courier> &get_couriers(){return this -> repo.get_couriers();}
    void saveToFile() { this -> repo.saveToFile(); }
    void addPackage(Package p);
    ~Service() = default;
};


#endif //INC_1ST_QT_PROJECT_SERVICE_H
