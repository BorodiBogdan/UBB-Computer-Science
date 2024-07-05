//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_SERVICE_H
#define RESEARCH_SERVICE_H
#include "Repository.h"

class Service {
private:
    Repository repository;
public:
    Service() = default;
    vector<Ideea> &getIdeas();
    vector <Researcher> &getResearchers(){return this -> repository.getResearchers(); }
    void addIdeea(Ideea idea){this -> repository.addIdeea(idea); }
    void saveAllToFile(){this -> repository.saveAllToFile(); }
    void saveIdeeaToFile(Ideea idea){this -> repository.saveIdeeaToFile(idea); }
};


#endif //RESEARCH_SERVICE_H
