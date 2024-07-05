//
// Created by Bob on 6/27/2024.
//

#ifndef FINAL_EXAM_28JUNE_REPOSITORY_H
#define FINAL_EXAM_28JUNE_REPOSITORY_H
#include "Package.h"
#include "Courier.h"

class Repository {
private:
    vector<Package> packages;
    vector<Courier> couriers;
    void readFromFile();
public:
    Repository(){readFromFile(); }
    vector<Package> &getPackages(){return this -> packages;}
    vector<Courier> &getCouriers(){ return this -> couriers; }
    void addPackage(Package p){ this-> packages.push_back(p);}
    void addCouriers(Courier c){ this -> couriers.push_back(c); }

};


#endif //FINAL_EXAM_28JUNE_REPOSITORY_H
