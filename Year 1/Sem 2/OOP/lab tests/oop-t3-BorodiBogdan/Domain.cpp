//
// Created by Bob on 5/28/2024.
//

#include "Domain.h"

Item::Item(string name, string keywords, string content) {
    this -> name = name;
    this -> keywords = keywords;
    this -> content = content;
}

string Item::getName() {
    return this -> name;
}

string Item::getKeyWords() {
    return this -> keywords;
}

string Item::getContent() {
    return this -> content;
}
