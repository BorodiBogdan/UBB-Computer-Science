//
// Created by Bob on 6/25/2024.
//

#ifndef MICROBIAL_BIOLOGIST_H
#define MICROBIAL_BIOLOGIST_H
#include <string>
#include <vector>
#include "Bacteria.h"
using namespace std;

class Biologist {
private:
    string name;
    vector<string> bacteriaNameList;
    vector <Bacteria> bacteriaList;
public:
    Biologist() = default;
    Biologist(string name, vector <string> bacteriaList) : name(name), bacteriaNameList(bacteriaList){};
    string getName(){return this -> name; }
    vector<string> &getBacteriaNameList(){return this -> bacteriaNameList; }
    vector<Bacteria> &getBacteriaList(){return this -> bacteriaList; }
    void addBacteria(Bacteria bacteria) { this -> bacteriaList.push_back(bacteria); }

    friend istream &operator >>(istream &in, Biologist &biologist);
    friend ostream &operator <<(ostream &out, Biologist biologist);
};


#endif //MICROBIAL_BIOLOGIST_H
