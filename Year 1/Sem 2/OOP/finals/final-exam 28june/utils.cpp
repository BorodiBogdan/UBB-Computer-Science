//
// Created by Bob on 6/26/2024.
//

#include "utils.h"

vector<string> utils::tokenize(string line, string sep) {
    string word;
    vector<string> tokens;

    for(auto c : line){
        if(sep.find(c) == -1)
            word += c;
        else{
            tokens.push_back(word);
            word = "";
        }
    }
    tokens.push_back(word);

    return tokens;
}
