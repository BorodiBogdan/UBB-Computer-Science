//
// Created by Bob on 6/26/2024.
//

#include "Repository.h"

#include <fstream>
#include <algorithm>

void Repository::readFromFile(){
    ifstream readResearchers("researchers.txt");
    ifstream readIdeeas("ideas.txt");

    Researcher re;

    while(readResearchers >> re)
        this -> researchers.push_back(re);

    Ideea id;

    while(readIdeeas >> id) {
        this->ideas.push_back(id);

        for(auto &r : this->researchers)
            if(r.getName() == id.getCreator())
                r.addIdea(ideas[ideas.size() - 1]);
    }
}

void Repository::saveAllToFile() {
    ofstream writeResearchers("allResearchers.txt");

    vector <Ideea> ideas = this -> ideas;

    sort(ideas.begin(), ideas.end(), [](Ideea a, Ideea b)->bool{
        return a.getDuration() < b.getDuration();
    });

    for(auto i : ideas)
        if(i.getStatuts() == "accepted")
            writeResearchers << i << "\n";

    writeResearchers.close();
}

void Repository::saveIdeeaToFile(Ideea idea) {
    ofstream writeIdeea(idea.getTitle());

    writeIdeea << idea;
}
