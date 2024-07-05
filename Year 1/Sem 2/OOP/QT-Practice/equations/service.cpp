//
// Created by Bob on 5/27/2024.
//

#include "service.h"

vector<equation> Service::getEquations() {
    return this -> repo.getEquations();
}

void Service::updateEq(int index, equation eq) {
    this -> repo.updateEq(index, eq);
}
