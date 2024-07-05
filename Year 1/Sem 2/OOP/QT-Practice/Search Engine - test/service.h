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
    vector<Document> getDocuments();
    vector<Document> getMatchingStrings(string name);
    Document getBestMatch(string name);
};


#endif //EQUATIONS_SERVICE_H
