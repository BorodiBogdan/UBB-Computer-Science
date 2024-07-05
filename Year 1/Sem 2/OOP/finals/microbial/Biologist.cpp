//
// Created by Bob on 6/25/2024.
//

#include "Biologist.h"
#include "utils.h"
#include <QDebug>

istream &operator >>(istream &in, Biologist &biologist){
    string line;
    in >> line;

    if(line == "")
        return in;

    qDebug() << line;

    vector <string> bioInfo = utils::tokenize("|", line);
    vector<string> bacteriaList = utils::tokenize(",", bioInfo[1]);

    biologist = Biologist(bioInfo[0], bacteriaList);

    return in;
}

ostream &operator <<(ostream &out, Biologist biologist){
    out << biologist.getName() << "|";

    for(auto d : biologist.getBacteriaNameList())
        if(d != biologist.getBacteriaNameList().back())
            out << d << ",";
        else out << d;

    return out;
}