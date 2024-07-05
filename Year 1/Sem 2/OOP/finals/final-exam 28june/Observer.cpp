//
// Created by Bob on 6/28/2024.
//

#include "Observer.h"

void Subject::notify() {
    for(auto obs : this -> obsList)
        obs->update();
}
