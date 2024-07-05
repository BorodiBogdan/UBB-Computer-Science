//
// Created by Bob on 6/25/2024.
//

#ifndef MICROBIAL_SERVICE_H
#define MICROBIAL_SERVICE_H
#include "Biologist.h"
#include "Bacteria.h"

class Service {
private:
    vector<Bacteria> bacteriaList;
    vector<Biologist>biologistList;
    void ReadFromFile();
    void SaveToFile();

public:
    Service(){ReadFromFile(); }
    vector<Bacteria> &getBacteriaList();
    vector<Biologist> &getBiologistList() {return this -> biologistList; };
    void addBacteria(Bacteria a){
        this -> bacteriaList.push_back(a);

        for(auto &biologist : this -> biologistList)
            for(auto c : biologist.getBacteriaList())
                if(c.getSpecies() == a.getSpecies())
                    biologist.addBacteria(c);

        SaveToFile();

    }
    ~Service(){SaveToFile();}
};


#endif //MICROBIAL_SERVICE_H
