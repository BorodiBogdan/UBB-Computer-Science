//
// Created by Bob on 5/26/2024.
//

#include "service.h"
#include <algorithm>
#include <cstring>
#include <QDebug>

vector<Item> Service::getItems() {
    return this -> repo.getItems();
}

vector<Item> Service::getItemsSortedByCategoryAndName() {
    vector<Item> itemList = this -> repo.getItems();

    sort(itemList.begin(), itemList.end(), [](const Item& a, const Item& b){
       if(a.getCategory() < b.getCategory())
           return true;
       else if(a.getCategory() == b.getCategory() && a.getName() < b.getName())
           return true;
        return false;
    });

    return itemList;
}

vector<Item> Service::getItemMatching(string name) {
    vector <Item> items;

    for(auto item : this -> repo.getItems()){
        if(strstr(item.getName().c_str(), name.c_str())) {
            items.emplace_back(item);

        }
    }
    return  items;
}

vector<Item> Service::getItemsByCategory(string category) {
    vector <Item> items;

    for(auto item : this -> repo.getItems()){
        if(item.getCategory() == category) {
            items.emplace_back(item);

        }
    }

    sort(items.begin(), items.end(), [](Item a, Item b){
       return a.getQuantity() < b.getQuantity();
    });
    return  items;
}
