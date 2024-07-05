//
// Created by Bob on 6/24/2024.
//

#include "Repository.h"
#include <fstream>

void Repository::readFromFile() {
    ifstream readUsers("users.txt");
    ifstream readItems("items.txt");

    User user;
    Item item;

    while(readUsers >> user)
        this -> userList.push_back(user);

    while(readItems >> item)
        this -> itemList.push_back(item);
}

Item Repository::getItemByName(string name) {
    for (auto u : itemList)
        if(u.getName() == name)
            return u;

    throw exception();
}

void Repository::saveToFile() {
    ofstream fout("items.txt");

    for(auto i : itemList)
        fout << i << "\n";
}

void Repository::addOffer(tuple<string, string, string> offer, string name) {
    for(auto &i : this -> itemList)
        if(i.getName() == name)
            i.addOffer(offer);
}

void Repository::updatePrice(string name, int price) {
    for (auto &i: this->itemList)
        if (i.getName() == name)
            i.setPrice(price);
}