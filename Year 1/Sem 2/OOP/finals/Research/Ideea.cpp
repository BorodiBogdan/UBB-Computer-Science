//
// Created by Bob on 6/26/2024.
//

#include "Ideea.h"
#include <sstream>
#include "utils.h"

istream &operator>>(istream &in, Ideea &ideea){
    string line;
    getline(in, line);

    if(line == "")
        return in;

    vector<string> tokens = utils::tokenize(line, "|");

    ideea = Ideea(tokens[0], tokens[1], tokens[2], tokens[3], stoi(tokens[4]));

    return in;
}
ostream &operator<<(ostream& out, Ideea ideea){
    string sep = "|";
    out << ideea.getTitle() << sep << ideea.getDescription() << sep << ideea.getStatuts() << sep << ideea.getCreator() << sep << to_string(ideea.getDuration());

    return out;
}