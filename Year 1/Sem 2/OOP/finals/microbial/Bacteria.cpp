#include "Bacteria.h"
#include "utils.h"
#include <qdebug.h>

Bacteria::Bacteria(string name, string species, string size, vector<string> diseases){
    this -> name = name;
    this -> species = species;
    this -> size = stoi(size);
    this -> diseases = diseases;
}

istream &operator >>(istream &in, Bacteria &bacteria){
    string line;

    in >> line;

    if(line == "")
        return in;

    qDebug() << line;

    vector <string> bacteriaInfo = utils::tokenize("|", line);
    qDebug() << bacteriaInfo[0];

    vector<string>deseases = utils::tokenize(",", bacteriaInfo[3]);


    bacteria = Bacteria(bacteriaInfo[0], bacteriaInfo[1], bacteriaInfo[2], deseases);

    return in;
}
ostream &operator <<(ostream &out, Bacteria &bacteria){
    out << bacteria.toString();

    return out;
}

string Bacteria::toString() const{
    string info = "";

    info = info + name + "|" + species + "|" + to_string(size) + "|";

    info += deseaseToString();

    return info;
}

string Bacteria::deseaseToString() const {
    string s = "";

    for(auto d : this ->diseases)
        if(d != this->diseases.back())
            s += d + ",";
        else s += d;

    return s;
}
