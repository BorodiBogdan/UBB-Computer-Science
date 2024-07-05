//
// Created by Bob on 5/27/2024.
//

#include "repository.h"

vector<equation> Repository::getEquations() {
    return this -> equationList;
}

void Repository::readFromFile() {
    ifstream fin("file.txt");
    equation e;

    while (fin >> e){
        this -> equationList.push_back(e);
    }
}

Repository::Repository() {
    this ->readFromFile();
}

void Repository::updateEq(int index, equation eq) {
    this -> equationList[index ] = eq;
}
