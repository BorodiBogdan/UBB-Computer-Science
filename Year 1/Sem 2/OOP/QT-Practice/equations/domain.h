//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_DOMAIN_H
#define EQUATIONS_DOMAIN_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class equation {
private:
    int x2, x, c;
public:
    equation();
    equation(int x2, int x, int c);
    int getX2();
    int getX();
    int getC();
    void setX2(int x2);
    void setX(int x);
    void setC(int c);
    bool isReal();

    friend istream& operator >>(istream& in, equation& e);
};
void trimWhiteSpaces(string &s);

#endif //EQUATIONS_DOMAIN_H
