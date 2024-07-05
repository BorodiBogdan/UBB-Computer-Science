//
// Created by Bob on 5/28/2024.
//

#include "Repository.h"
#include <fstream>

vector<Weather> Repository::getWeatherList() {
    return this -> weatherList;
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

    while(getline(fin, line)){
        try {
            vector<string> tokens;

            string token = "";
            for (auto x: line) {

                if (x != ';')
                    token += x;
                else {
                    trimWhiteSpaces(token);
                    tokens.push_back(token);
                    token = "";
                }
            }

            trimWhiteSpaces(token);
            tokens.push_back(token);

            Weather w = Weather(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]), stoi(tokens[3]), tokens[4]);

            this->weatherList.push_back(w);
        }
        catch (exception &e){};
    }
}

Repository::Repository() {
    this -> readFromFile();
}
