//
// Created by Bob on 5/22/2024.
//

#ifndef OOPTEST_REPOSITORY_H
#define OOPTEST_REPOSITORY_H
#include "../domain/domain.h"
#include <vector>

class Repository {
private:
    vector <Bill> billList;
public:
    Repository();
    vector <Bill> getBills();
    void addBill(Bill bill);
    void readFromFile();
};


#endif //OOPTEST_REPOSITORY_H
