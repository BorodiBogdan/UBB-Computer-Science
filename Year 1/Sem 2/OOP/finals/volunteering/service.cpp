//
// Created by Bob on 6/23/2024.
//

#include "service.h"

vector<department> service::getDepartments() const {
    return this -> repo.getDepartments();
}
vector <volunteer> service::getVolunteers() const {
    return this -> repo.getVolunteers();
}
