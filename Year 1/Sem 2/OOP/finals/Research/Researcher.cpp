//
// Created by Bob on 6/26/2024.
//

#include "Researcher.h"
#include <string>
#include "utils.h"
#include <qdebug.h>

istream &operator>>(istream &in, Researcher &researcher){
    string line;

    getline(in, line);

    if(line == "")
        return in;

    vector<string> tokens = utils::tokenize(line, "|");
    researcher = Researcher(tokens[0], tokens[1]);

    return in;
}
ostream &operator<<(ostream &out, Researcher &researcher){
    string sep = "|";
    out << researcher.getName() << sep << researcher.getPosition();

    return out;
}