//
// Created by Bob on 6/28/2024.
//

#include "Courier.h"
#include "utils.h"
#include <sstream>

istream  &operator>>(istream &input, Courier &courier){
    string line;
    getline(input, line);

    if(line == "")
        return input;

    vector<string> tokens = utils::tokenize(line, "|");
    string name = tokens[0];
    vector <string> streets = utils::tokenize(tokens[1], ",");
    vector<string> packages = utils::tokenize(tokens[2], ",");
    Circle zone = {stoi(packages[0]), stoi(packages[1]), stoi(packages[2])};

    courier = Courier(name, streets, zone);
    return input;
}
 ostream  &operator<<(ostream &output, Courier &courier){
    string sep = "|";
    output << courier.getName() << sep;

    for(auto &street : courier.getStreets())
        output << street << ",";

    output << sep << courier.getZone().x << "," << courier.getZone().y << "," << courier.getZone().r;

    return output;
}

bool Courier::isPackage(Package package) {
    for(auto p : this -> packages)
        if(*p == package)
            return true;

    return false;
}
