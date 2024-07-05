//
// Created by Bob on 6/27/2024.
//

#include <qdebug.h>
#include "Repository.h"
#include <fstream>

void Repository::readFromFile() {
    ifstream readPackages("packages.txt");
    ifstream readCouriers("couriers.txt");

    Package p;

    while(readPackages >> p) {
        this->packages.push_back(p);
        qDebug() << p.getNumber();
    }
    Courier c;

    while(readCouriers >> c) {
        this->couriers.push_back(c);
        qDebug() << c.getName();
    }
    qDebug() << "Done";
}