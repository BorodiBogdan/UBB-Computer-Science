//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_UTILS_H
#define RESEARCH_UTILS_H
#include "Repository.h"
#include "Observer.h"
using  namespace std;

class Service : public Subject{
private:
    Repository repo;
public:
    vector <Package> &getPackages(){ return repo.getPackages();}
    vector <Courier> &getCouriers(){ return repo.getCouriers();}
    void addPackage(Package p){ this -> repo.addPackage(p); }
    void addCourier(Courier c){ repo.addCouriers(c); }
};


#endif //RESEARCH_UTILS_H
