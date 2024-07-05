//
// Created by Bob on 5/26/2024.
//

#ifndef INC_1ST_QT_PROJECT_REPOSITORY_H
#define INC_1ST_QT_PROJECT_REPOSITORY_H
#include "domain.h"
#include <vector>

class Repository {
private:
    vector <Item> itemList;
public:
    Repository();
    vector<Item>getItems();
    void addItem(Item);
    void readItems();
};


#endif //INC_1ST_QT_PROJECT_REPOSITORY_H
