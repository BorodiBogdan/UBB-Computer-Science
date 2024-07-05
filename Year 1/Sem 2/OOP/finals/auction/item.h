//
// Created by Bob on 6/24/2024.
//

#ifndef INC_1ST_QT_PROJECT_ITEM_H
#define INC_1ST_QT_PROJECT_ITEM_H
#include <string>
#include <vector>
using namespace std;

class Item {
private:
    string name, category;
    int price;
    vector<tuple<string, string, string>> listOfOffers;
public:
    Item() = default;
    Item(string name, string category, int price, vector<tuple<string, string, string>>  listOfOffers) : name(name), category(category), price(price), listOfOffers(listOfOffers){};
    string getName(){return this -> name;}
    string getCategory(){return this -> category;}
    int getPrice(){ return this -> price;}
    vector<tuple<string, string, string>>  getOffers(){return this -> listOfOffers;};
    void addOffer(tuple<string, string, string> offer) {this -> listOfOffers.push_back(offer); }
    void setPrice(int price) {this -> price = price; }

    friend istream &operator >>(istream &in, Item &item);
    friend ostream &operator <<(ostream &out, Item &item);
};


#endif //INC_1ST_QT_PROJECT_ITEM_H
