//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_SERVICE_H
#define EQUATIONS_SERVICE_H
#include "repository.h"

class Service {
private:
Repository repo;
public:
    vector<equation>getEquations();
    void updateEq(int index, equation eq);
};


#endif //EQUATIONS_SERVICE_H
