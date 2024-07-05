//
// Created by Bob on 5/28/2024.
//

#include "Repository.h"
#include <fstream>

Repository::Repository() {
    this -> readFromFile();
}

vector<Item> Repository::getItems() {
    return this -> itemList;
}

void trimWhiteSpaces(string &s){
    while(s[0] == ' ')
        s.erase(0, 1);
    while(s[s.length() - 1] == ' ')
        s.erase(s.length() -1, 1);
}

void Repository::readFromFile() {
    ifstream fin("file.txt");

    string line = "";

    while(getline(fin, line)){
        vector<string> tokens;
        string token = "";

        for(auto x : line){
            if(x != '|')
                token += x;
            else{
                trimWhiteSpaces(token);
                tokens.push_back(token);
                token = "";
            }
        }

        trimWhiteSpaces(token);
        tokens.push_back(token);
        token = "";

        Item a = Item(tokens[0], tokens[1], tokens[2]);

        this -> itemList.push_back(a);
    }
}
