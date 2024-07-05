//
// Created by Bob on 6/23/2024.
//

#include "department.h"

string department::getName() const {
    return this -> name;
}

string department::getDescription() const {
    return this -> description;
}

department::department(string name, string description) {
    this->name = name;
    this->description = description;
}
