//
// Created by Bob on 5/22/2024.
//

#include "Service.h"

vector<Bill> Service::getBills() {
    return this -> repository.getBills();
}

void Service::addBill(Bill bill) {
    this->repository.addBill(bill);
}

vector<Bill> Service::getUnpaidBills( bool isPayed) {
    vector<Bill> unpaidBills;

    for(auto bill : this ->repository.getBills())
        if(bill.getIsPaid() == isPayed)
            unpaidBills.push_back(bill);

    return unpaidBills;
}

float Service::totalOfUnpaidBills(string companyName) {
    float sum = 0;
    bool ok = false;

    for(auto bill : this ->repository.getBills()) {
        if(bill.getCompanyName() == companyName)
            ok = true;

        if (bill.getCompanyName() == companyName && bill.getIsPaid() == false)
            sum += bill.getSum();
    }

    if(ok == false)
        return -1;

    return sum;
}
