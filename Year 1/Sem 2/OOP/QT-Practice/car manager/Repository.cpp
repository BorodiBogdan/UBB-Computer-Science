//
// Created by Bob on 5/27/2024.
//

#include "Repository.h"
#include <fstream>
#include <QDebug>

Repository::Repository() {
    this -> readFromFile();
}

vector<Car> Repository::getCars() {
    return this -> carList;
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
    string token = "";

    while(getline(fin, line)) {
        vector<string>tokens;

        for (auto letter: line) {
            if (letter == '|') {
                trimWhiteSpaces(token);
                tokens.push_back(token);
                token = "";
            } else
                token += letter;
        }
        trimWhiteSpaces(token);
        tokens.push_back(token);
        token = "";

        Car carToBeAdded = Car(tokens[0], tokens[1], stoi(tokens[2]), tokens[3]);

        this->carList.push_back(carToBeAdded);
    }
}

void Repository::addCar(Car a) {
    this -> carList.push_back(a);
}
