//
// Created by Bob on 5/28/2024.
//

#ifndef OOPTEST_REPOSITORY_H
#define OOPTEST_REPOSITORY_H
#include "Domain.h"
#include <vector>

class Repository {
private:
    vector<Item> itemList;
public:
    Repository();
    vector<Item> getItems();
    void readFromFile();
};


#endif //OOPTEST_REPOSITORY_H
