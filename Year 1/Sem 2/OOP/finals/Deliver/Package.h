//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_PACKAGE_H
#define INC_1ST_QT_PROJECT_PACKAGE_H
#include <string>
using namespace std;

struct Location{
    int x, y;

    bool operator == (const Location &other) const{
        return other.x == x && y == other.y;
    }
};

class Package {
private:
    string recipient;
    string street, number;
    Location location;
    string deliveryStatus;
public:
    Package() = default;
    Package(string recipient, string street, string number, Location location, string deliveryStatus) : recipient(recipient), street(street), number(number),
                                                                                                        location(location), deliveryStatus(deliveryStatus){}
    string getRecipient(){return this -> recipient;}
    string getStreet(){return  this -> street; }
    string getNumber(){return  this -> number;}
    string getDeliveryStatus(){return  this -> deliveryStatus;}
    Location getLocation(){return  this -> location;}
    void makeDelivery(){this -> deliveryStatus = "true";}
    string toString();
    bool operator == (const Package &other) const{
        return other.recipient == recipient && other.location == location && other.street == street && other.number == number;
    }

    friend istream &operator>>(istream &input, Package &package);
    friend ostream &operator<<(ostream &output, Package &package);
};


#endif //INC_1ST_QT_PROJECT_PACKAGE_H
