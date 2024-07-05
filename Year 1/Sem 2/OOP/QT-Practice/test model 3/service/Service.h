//
// Created by Bob on 5/22/2024.
//

#ifndef OOPTEST_SERVICE_H
#define OOPTEST_SERVICE_H
#include "../repository/Repository.h"

class Service {
private:
    Repository repository;
public:
    vector <Bill> getBills();
    vector <Bill> getUnpaidBills(bool isPayed);
    void addBill(Bill bill);
    float totalOfUnpaidBills(string companyName);
};


#endif //OOPTEST_SERVICE_H
