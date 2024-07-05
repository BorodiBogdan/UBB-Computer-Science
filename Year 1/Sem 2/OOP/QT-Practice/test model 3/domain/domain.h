//
// Created by Bob on 5/22/2024.
//

#ifndef TEST_MODEL_3_DOMAIN_H
#define TEST_MODEL_3_DOMAIN_H
#include <string>
using namespace  std;

class Bill {
private:
    string companyName,serialNumber;
    int sum;
    bool isPaid;
public:
    Bill(string companyName, string serialNumber, int sum, bool isPaid);
    string getCompanyName();
    string getSerialNumber();
    int getSum();
    bool getIsPaid();
};


#endif //TEST_MODEL_3_DOMAIN_H
