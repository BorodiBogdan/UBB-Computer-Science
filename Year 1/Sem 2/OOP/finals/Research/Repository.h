//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_REPOSITORY_H
#define RESEARCH_REPOSITORY_H
#include "Researcher.h"
#include "Ideea.h"

class Repository {
private:
    vector<Ideea> ideas;
    vector<Researcher> researchers;
    void readFromFile();
public:
    void saveAllToFile();
    void saveIdeeaToFile(Ideea idea);
    Repository() { readFromFile();}
    vector<Ideea> &getIdeas() {return this -> ideas; }
    vector <Researcher> &getResearchers(){return this -> researchers; }
    void addIdeea(Ideea idea){this -> ideas.push_back(idea); }
};


#endif //RESEARCH_REPOSITORY_H
