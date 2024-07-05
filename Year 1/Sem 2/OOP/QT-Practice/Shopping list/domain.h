//
// Created by Bob on 5/26/2024.
//

#ifndef INC_1ST_QT_PROJECT_DOMAIN_H
#define INC_1ST_QT_PROJECT_DOMAIN_H
#include <string>
using namespace std;

class Item {
private:
    string category, name;
    int quantity;
public:
    Item(string category, string name, int quantity);
    int getQuantity() const;
    string getCategory() const;
    string getName() const;
};


#endif //INC_1ST_QT_PROJECT_DOMAIN_H
