//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_RESEARCHER_H
#define RESEARCH_RESEARCHER_H
#include <vector>
#include <string>
#include "Ideea.h"
using namespace std;

class Researcher {
private:
    string name, position;
    vector <Ideea> ideas;
public:
    Researcher(string name = "", string position = ""): name(name), position(position){}
    string getName(){return this -> name; };
    string getPosition(){return this -> position;}
    void addIdea(Ideea &idea){this -> ideas.push_back(idea); }
    vector<Ideea> &getIdeas(){return this -> ideas; }

    friend istream &operator>>(istream &in, Researcher &researcher);
    friend ostream &operator<<(ostream &out, Researcher &researcher);

};


#endif //RESEARCH_RESEARCHER_H
