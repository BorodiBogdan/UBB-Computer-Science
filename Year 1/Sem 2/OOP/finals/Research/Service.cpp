//
// Created by Bob on 6/26/2024.
//

#include "Service.h"
#include <fstream>
#include <algorithm>

vector<Ideea> &Service::getIdeas() {

    sort(this -> repository.getIdeas().begin(), repository.getIdeas().end(), [](Ideea &a, Ideea &b){
        return a.getDuration() < b.getDuration();
    });

    return this -> repository.getIdeas();
}
