//
// Created by Bob on 5/28/2024.
//

#ifndef OOPTEST_DOMAIN_H
#define OOPTEST_DOMAIN_H
#include <string>
using namespace std;

class Item {
private:
    string name, keywords, content;
public:
    Item(string name, string keywords, string content);
    string getName();
    string getKeyWords();
    string getContent();
};


#endif //OOPTEST_DOMAIN_H
