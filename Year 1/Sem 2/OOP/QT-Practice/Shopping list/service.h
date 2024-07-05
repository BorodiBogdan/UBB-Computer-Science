//
// Created by Bob on 5/26/2024.
//

#ifndef INC_1ST_QT_PROJECT_SERVICE_H
#define INC_1ST_QT_PROJECT_SERVICE_H
#include "repository.h"

class Service {
private:
    Repository repo;
public:
    vector<Item>getItems();
    vector<Item>getItemsSortedByCategoryAndName();
    vector<Item>getItemMatching(string name);
    vector<Item> getItemsByCategory(string category);
};


#endif //INC_1ST_QT_PROJECT_SERVICE_H
