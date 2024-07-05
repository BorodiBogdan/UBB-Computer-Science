#ifndef INC_1ST_QT_PROJECT_COURIER_H
#define INC_1ST_QT_PROJECT_COURIER_H
#include <vector>
#include <string>
#include "Package.h"
using namespace std;

struct Circle {
    int x, y, r;
};

class Courier {
private:
    string name;
    vector<string> streets;
    Circle zone;
    vector <Package*> packages;
public:
    Courier() = default;
    Courier(string name, vector<string> streets, Circle zone) : name{name}, streets{streets}, zone{zone} {}
    string &getName()  {return this -> name;}
    vector<string> &getStreets()  {return this -> streets;}
    Circle &getZone()  {return this -> zone;}
    void setName(string name) {this -> name = name;}
    void addPackage(Package *package) { this -> packages.push_back(package);}
    vector <Package*> &getPackages() {return this -> packages;}

    friend istream  &operator>>(istream &input, Courier &courier);
    friend ostream  &operator<<(ostream &output, Courier &courier);
};


#endif //INC_1ST_QT_PROJECT_COURIER_H
