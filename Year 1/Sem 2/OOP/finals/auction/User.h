//
// Created by Bob on 6/24/2024.
//

#ifndef INC_1ST_QT_PROJECT_USER_H
#define INC_1ST_QT_PROJECT_USER_H
#include <string>
using namespace std;

class User {
private:
    string name, type;
    int id;
public:
    User() = default;
    User(string name, int id, string type) : name(name), id(id), type(type){};
    string getName() { return  name; }
    string getType() { return type; }
    int getId() {return  id;}

    friend istream &operator >>(istream &in, User &user);

};


#endif //INC_1ST_QT_PROJECT_USER_H
