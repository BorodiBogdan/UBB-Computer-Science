//
// Created by Bob on 5/28/2024.
//

#ifndef OOPTEST_SERVICE_H
#define OOPTEST_SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository repository;
public:
    vector<Item> getItemsSortedByLength();
    vector<Item> getItemsByString(string name);
    float computeSImilarity(string textFromLineEdit, string textFromSelectedItem);
};


#endif //OOPTEST_SERVICE_H
