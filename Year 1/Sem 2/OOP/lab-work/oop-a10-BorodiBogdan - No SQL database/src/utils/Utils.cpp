//
// Created by Bob on 5/10/2024.
//
#include "../../includes/utils/Utils.h"

void Utils::trimWhiteSpaces(std::string &str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}