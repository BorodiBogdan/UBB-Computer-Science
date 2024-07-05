//
// Created by Bob on 6/25/2024.
//

#include "utils.h"

vector<string> utils::tokenize(string tokens, string text) {
    string word = "";
    vector <string> words;

    for(auto x: text){
        if(tokens.find(x) != -1){
            words.push_back(word);
            word = "";
        }
        else word += x;
    }
    words.push_back(word);
    return words;
}
