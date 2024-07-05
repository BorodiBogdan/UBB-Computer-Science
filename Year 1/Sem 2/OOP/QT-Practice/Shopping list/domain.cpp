//
// Created by Bob on 5/26/2024.
//

#include "domain.h"

int Item::getQuantity() const{
    return this -> quantity;
}

string Item::getCategory() const{
    return this -> category;
}

string Item::getName() const{
    return this -> name;
}

Item::Item(string category, string name, int quantity) {
    this -> category = category;
    this -> name = name;
    this -> quantity = quantity;
}