//
// Created by Bob on 5/26/2024.
//

#include "repository.h"
#include <fstream>
#include <cstring>
#include <iostream>

void Repository::addItem(Item item) {
    this -> itemList.push_back(item);
}

vector<Item> Repository::getItems() {
    return this-> itemList;
}

void trimWhiteSpaces(string &item){
    while(item[0] == ' ')
        item.erase(0, 1);

    while(item[item.length() - 1] == ' ')
        item.erase(item.length() - 1, 1);
}

void Repository::readItems() {
    ifstream fin("file.txt");

    char itemLine[256];

    string itemSpecification = "";

    while(fin.getline(itemLine, 255)){
        vector <string> productSpecs;

        for(int i = 0; i < strlen(itemLine); ++i) {
            if(itemLine[i] == '|'){
                trimWhiteSpaces(itemSpecification);
                productSpecs.push_back(itemSpecification);
                itemSpecification = "";
            }
            else
                itemSpecification += itemLine[i];
        }

        trimWhiteSpaces(itemSpecification);
        productSpecs.push_back(itemSpecification);
        itemSpecification = "";

        Item itemToBeAdded = Item(productSpecs[0], productSpecs[1], stoi(productSpecs[2]));
        this ->addItem(itemToBeAdded);
    }
}

Repository::Repository() {
    this -> readItems();
}
