//
// Created by Bob on 6/28/2024.
//

#include "Package.h"
#include <sstream>
#include "utils.h"

istream &operator>>(istream &input, Package &package){
    string line;

    getline(input, line);

    if(line == "")
        return input;

    vector<string> tokens = utils::tokenize(line, "|");
    string recipient = tokens[0];
    vector <string> adressAndNumber = utils::tokenize(tokens[1], ",");
    string adress = adressAndNumber[0];
    string number = adressAndNumber[1];
    vector <string> location = utils::tokenize(tokens[2], ",");
    Location loc = {stoi(location[0]), stoi(location[1])};
    string deliveryStatus = tokens[3];

    package = Package(recipient, adress, number, loc, deliveryStatus);

    return input;

}
ostream &operator<<(ostream &output, Package &package){
    output << package.toString();

    return output;
}

string Package::toString() {
    string sep = "|";
    string text = recipient + sep + street + sep + number + sep + to_string(location.x) + "," + to_string(location.y) + sep + deliveryStatus;

    return text;
}
