//
// Created by Bob on 5/22/2024.
//

#include "Repository.h"
#include <fstream>
#include <cstring>
#include <iostream>

vector<Bill> Repository::getBills() {
    return this -> billList;
}

void Repository::addBill(Bill bill) {
    this -> billList.push_back(bill);
}

Repository::Repository() {
    this->readFromFile();
}

void Repository::readFromFile() {
    ifstream fin("billList.in");

    char line[257];
    string arguments[6];

    while(fin.getline(line, 256)){
        string word = "";
        int cnt = 0;
        for(int index = 0; index < strlen(line); ++index){
            if(line[index] != ';')
                word += line[index];
            else{
                arguments[cnt++] = word;
                word = "";
            }
        }
        arguments[cnt++] = word;

        string companyName = arguments[0];
        string code = arguments[1];
        float sum = stof(arguments[2]);
        bool isPaid;

        if(arguments[3] == "false")
            isPaid = false;
        else isPaid = true;

        Bill bill = Bill(companyName, code, sum, isPaid);
        this->addBill(bill);
    }
}
