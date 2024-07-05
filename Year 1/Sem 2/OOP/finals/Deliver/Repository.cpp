//
// Created by Bob on 6/28/2024.
//

#include "Repository.h"
#include <fstream>
#include <cmath>
#include <qdebug.h>

double computeDistance(int x1, int y1, int x2, int y2){
    return  sqrt((x1-x2) * (x1-x2) + (y1 -y2) *(y1 - y2));
}
bool isInZone(Courier courier, Package p){
    return computeDistance(courier.getZone().x, courier.getZone().y, p.getLocation().x, p.getLocation().y) <= courier.getZone().r;
}

void Repository::readFromFile() {
    ifstream readPackages("packages.txt");
    ifstream readCouriers("couriers.txt");

    Courier courier;

    while(readCouriers >> courier){
        this -> couriers.push_back(courier);
    }

    Package package;

    while(readPackages >> package){
        this -> packages.push_back(package);
    }

    for(auto &courier: this -> couriers)
        for(auto &street : courier.getStreets())
            for(auto &package: this -> packages){
                if(package.getStreet() == street || isInZone(courier, package)){
                    if(courier.isPackage(package) == 0)
                        courier.addPackage(&package);
                }
    };

}
void Repository::addPackage(Package p) {
    this -> packages.push_back(p);

    for(auto &courier: this -> couriers)
        for(auto &street : courier.getStreets()){
            qDebug() << computeDistance(courier.getZone().x, courier.getZone().y, p.getLocation().x, p.getLocation().y);
            if(p.getStreet() == street){
                courier.addPackage(&packages[packages.size() - 1]);
            }
        }
    saveToFile();
}

void Repository::saveToFile() {
    ofstream writePackages("packages.txt");

    for(auto &package: this -> packages){
        writePackages << package <<"\n";
    }
}
