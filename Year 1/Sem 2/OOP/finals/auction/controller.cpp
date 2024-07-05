//
// Created by Bob on 6/24/2024.
//

#include "controller.h"

vector <Item> controller::getItems(){
    vector <Item> v = this -> repo.getItems();

    sort(v.begin(), v.end(), [](Item a, Item b)->bool{
        return a.getPrice() < b.getPrice();
    });

    return v;
}