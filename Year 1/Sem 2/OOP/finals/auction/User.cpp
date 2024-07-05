//
// Created by Bob on 6/24/2024.
//

#include "User.h"
#include <cstring>
#include <fstream>
#include "utils.h"
using namespace std;

istream &operator >>(istream &in, User &user){
    string line;

    if(! getline(in, line))
        return in;

    utils u;

    vector<string> tokens = u.tokenize("|", line);

    user = User(tokens[0], stoi(tokens[1]), tokens[2]);

    return in;
}