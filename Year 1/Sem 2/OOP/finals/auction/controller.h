//
// Created by Bob on 6/24/2024.
//

#ifndef INC_1ST_QT_PROJECT_CONTROLLER_H
#define INC_1ST_QT_PROJECT_CONTROLLER_H
#include "Repository.h"
#include "Observer.h"

class controller : public Subject{
private:
    Repository repo;
public:
    vector <User> getUsers() { return repo.getUsers(); }
    vector <Item> getItems();
    void addItem(Item a) { this -> repo.addItem(a);}
    Item getItemByName(string name){return this -> repo.getItemByName(name);}
    void addOffer(tuple <string, string, string> offer, string name){this -> repo.addOffer(offer, name);}
    void updatePrice(string name, int price) { this -> repo.updatePrice(name, price); }
};


#endif //INC_1ST_QT_PROJECT_CONTROLLER_H
