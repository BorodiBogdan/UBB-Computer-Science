//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_REPOSITORY_H
#define INC_1ST_QT_PROJECT_REPOSITORY_H
#include "Package.h"
#include <vector>
using namespace std;
#include "Courier.h"

class Repository {
private:
    vector<Package>packages;
    vector<Courier>couriers;
    void readFromFile();
public:
    void saveToFile();
    ~Repository(){ saveToFile();}
    Repository() { readFromFile();}
    vector<Package> &get_packages(){return this -> packages;}
    vector<Courier> &get_couriers(){return this -> couriers;}
    void addPackage(Package p);
};


#endif //INC_1ST_QT_PROJECT_REPOSITORY_H
