//
// Created by Bob on 5/22/2024.
//

#include "domain.h"

bool Bill::getIsPaid() {
    return this -> isPaid;
}

int Bill::getSum() {
    return this -> sum;
}

string Bill::getCompanyName() {
    return this -> companyName;
}

string Bill::getSerialNumber() {
    return this -> serialNumber;
}

Bill::Bill(string companyName, string serialNumber, int sum, bool isPaid) {
    this -> companyName = companyName;
    this -> serialNumber = serialNumber;
    this -> sum = sum;
    this -> isPaid = isPaid;
}
