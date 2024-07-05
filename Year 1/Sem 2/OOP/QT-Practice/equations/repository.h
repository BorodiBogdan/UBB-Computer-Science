//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_REPOSITORY_H
#define EQUATIONS_REPOSITORY_H
#include "domain.h"
#include <vector>

class Repository {
private:
    vector<equation> equationList;
public:
    Repository();
    vector <equation> getEquations();
    void readFromFile();
    void updateEq(int index, equation eq);
};


#endif //EQUATIONS_REPOSITORY_H
