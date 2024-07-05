//
// Created by Bob on 5/27/2024.
//

#include "repository.h"
#include <fstream>

Repository::Repository() {
    this -> readFromFile();
}

void trimWhiteSpaces(string &s){
    while(s[0] == ' ')
        s.erase(0, 1);

    while(s[s.length() - 1] == ' ')
        s.erase(s.length() - 1, 1);
}
void Repository::readFromFile() {
    ifstream fin("file.txt");

    string line;

    while(getline(fin,line)) {
        try {
            string token = "";
            vector<string> tokens;

            for (auto x: line) {
                if (x == '|') {
                    trimWhiteSpaces(token);
                    tokens.push_back(token);
                    token = "";
                } else
                    token += x;
            }

            trimWhiteSpaces(token);
            tokens.push_back(token);

            Document a = Document(tokens[0], tokens[1], tokens[2]);

            this->documentList.push_back(a);
        }
        catch (exception &e){

        }
    }
}

vector<Document> Repository::getDocuments() {
    return this -> documentList;
}
