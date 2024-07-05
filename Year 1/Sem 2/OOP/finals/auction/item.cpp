//
// Created by Bob on 6/24/2024.
//

#include "item.h"
#include <fstream>
#include <string>
#include <QDebug>
#include "utils.h"
using namespace std;

istream &operator >>(istream &in, Item &item){
    string line;

    if(! getline(in, line))
        return in;
    utils u;

    vector<string> tokens = u.tokenize("|", line);
    vector<string> offerList = u.tokenize(", " , tokens[3]);

    vector<tuple<string, string, string>> offerListTuple;

    for(int i = 0; i < offerList.size(); i += 3){
        qDebug() << offerList[i];
        tuple<string, string, string> t(offerList[i], offerList[i + 1], offerList[i + 2]);
        offerListTuple.push_back(t);
    }

    item = Item(tokens[0], tokens[1], stoi(tokens[2]), offerListTuple);

    return in;
}
ostream &operator <<(ostream &out, Item &item){
    out << item.getName() << "|" << item.getCategory() <<"|" << item.getPrice() <<"|";

    for(auto x : item.getOffers())
        out << get<0>(x) << "," << get<1>(x) << "," << get<2>(x) << ",";

    return out;
}