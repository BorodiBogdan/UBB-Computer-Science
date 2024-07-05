//
// Created by Bob on 5/27/2024.
//

#include "domain.h"
#include <QDebug>

int equation::getX2() {
    return this -> x2;
}

int equation::getX() {
    return this -> x;
}

int equation::getC() {
    return this -> c;
}

void equation::setX2(int x2) {
    this -> x2 = x2;
}

void equation::setX(int x) {
    this -> x = x;
}

void equation::setC(int c) {
    this-> c = c;
}

equation::equation(int x2, int x, int c) {
    this -> x2 = x2;
    this -> x = x;
    this -> c = c;
}
void trimWhiteSpaces(string &s){
    while(s[0] == ' ')
        s.erase(0, 1);

    while(s[s.length() - 1] == ' ')
        s.erase(s.length() - 1, 1);
}
istream& operator >>(istream& in, equation& e){

    string line;
    getline(in, line);

    if(line == "")
        return in;

    string token = "";
    string tokens[3];
    int k = 0;

    for(auto e : line){
        if(e == ','){
            trimWhiteSpaces(token);
            tokens[k++] = token;
            token = "";
        }
        else
            token += e;

    }
    trimWhiteSpaces(token);
    tokens[k] = token;

   e.setX2(stoi(tokens[0]));
   e.setX(stoi(tokens[1]));
   e.setC(stoi(tokens[2]));

    return in;
}

equation::equation() {

}

bool equation::isReal() {
    if(x * x - 4 * x2 * c >= 0)
        return true;
    return false;
}
