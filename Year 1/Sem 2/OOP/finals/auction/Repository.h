//
// Created by Bob on 6/24/2024.
//

#ifndef INC_1ST_QT_PROJECT_REPOSITORY_H
#define INC_1ST_QT_PROJECT_REPOSITORY_H
#include "User.h"
#include "item.h"
#include <algorithm>

class Repository {
private:
    vector <User> userList;
    vector <Item> itemList;
    void readFromFile();
    void saveToFile();

public:
    Repository(){ readFromFile();
         }
    vector <User> getUsers() { return this -> userList; };
    vector<Item> getItems() { return this -> itemList; };
    void addItem(Item a) { this -> itemList.push_back(a); saveToFile();}
    Item getItemByName(string name);
    void addOffer(tuple<string, string, string> offer, string name);
    void updatePrice(string name, int price);

};


#endif //INC_1ST_QT_PROJECT_REPOSITORY_H
