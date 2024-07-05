//
// Created by Bob on 6/23/2024.
//

#include "volunteer.h"

volunteer::volunteer(string name, string email, vector <string> interests, string departmentName) {
    this->name = name;
    this->email = email;
    this->interests = interests;
    this->departmentName = departmentName;
}

string volunteer::getName() const {
    return this->name;
}

string volunteer::getEmail() const {
    return this->email;
}

vector<string> volunteer::getInterests() const {
    return this->interests;
}

string volunteer::getDepartment() const {
    return this->departmentName;
}