//
// Created by Bob on 6/25/2024.
//

#include "Service.h"
#include <fstream>
#include <algorithm>
using  namespace std;


void Service::ReadFromFile() {
    ifstream readBacteria("bacteria.txt");
    ifstream readBiologist("bologists.txt");

    Bacteria bact;

    while (readBacteria >> bact) {
        this->bacteriaList.push_back(bact);
    }

    Biologist bio;

    while (readBiologist >> bio) {
        this->biologistList.push_back(bio);
    }
    for (auto &biologist: biologistList)
        for (auto &bacteriaName: biologist.getBacteriaNameList())
            for (auto bacteria: bacteriaList)
                if (bacteria.getName() == bacteriaName)
                    biologist.addBacteria(bacteria);
}

vector<Bacteria> &Service::getBacteriaList() {
    sort(bacteriaList.begin(), bacteriaList.end(), [](Bacteria a, Bacteria b) -> bool{
       return a.getName() < b.getName();
    });

    return bacteriaList;
}

void Service::SaveToFile() {
    ofstream writeBacteria("bacteria.txt");
    ofstream writeBiologist("bologists.txt");

    for(auto bacteria : this ->bacteriaList)
        writeBacteria << bacteria << '\n';

    for(auto biologist : this -> biologistList)
        writeBiologist << biologist << "\n";
}
