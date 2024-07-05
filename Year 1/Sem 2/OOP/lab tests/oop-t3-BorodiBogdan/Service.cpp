//
// Created by Bob on 5/28/2024.
//

#include "Service.h"
#include <algorithm>

vector<Item> Service::getItemsSortedByLength() {
    vector <Item> itemList = this -> repository.getItems();

    sort(itemList.begin(), itemList.end(), [](Item a, Item b)->bool{
       return a.getContent().length() < b.getContent().length();
    });
    return itemList;
}

vector<Item> Service::getItemsByString(string name) {
    vector <Item> itemList;

    for(auto item : this -> repository.getItems()){
        if(item.getContent().find(name) != -1 || item.getName().find(name) != -1 || item.getKeyWords().find(name) != -1){
            itemList.push_back(item);
        }
    }
    return itemList;
}

float Service::computeSImilarity(string textFromLineEdit, string textFromSelectedItem) {
   float similarity;

    while(textFromSelectedItem[0] != '|')
        textFromSelectedItem.erase(0, 1);

    textFromSelectedItem.erase(0, 1);

    while(textFromSelectedItem[0] == ' ')
        textFromSelectedItem.erase(0, 1);

    if(textFromSelectedItem.length() < textFromLineEdit.length())
        swap(textFromLineEdit, textFromSelectedItem);

    //qDebug() << textFromSelectedItem <<" " << textFromLineEdit;

    if(textFromSelectedItem.find(textFromLineEdit) == -1)
        similarity = 0;
    else similarity = float(1.0 * textFromLineEdit.length() / textFromSelectedItem.length());

    return similarity;
}
