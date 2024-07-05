//
// Created by Bob on 6/25/2024.
//

#ifndef MICROBIAL_BACTERIA_H
#define MICROBIAL_BACTERIA_H

#include <string>
#include <vector>
using namespace  std;

class Bacteria{
private:
    string name, species;
    int size;
    vector<string> diseases;
public:
    Bacteria() = default;
    Bacteria(string name, string species, string size, vector<string> diseases);

    string getName() const { return this -> name; }
    string getSpecies() const{ return this -> species; }
    string deseaseToString() const;
    void setName(string name) {this -> name = name;};
    void setSize(string size) {this -> size = stoi(size); };
    void setSpecies(string species){this -> species = species; };
    int getSize() const{ return this -> size; }
    vector <string> &getDiseases(){ return this -> diseases; }
    string toString() const;

    friend istream &operator >>(istream &in, Bacteria &bacteria);
    friend ostream &operator <<(ostream &out, Bacteria &bacteria);
};


#endif //MICROBIAL_BACTERIA_H
