//
// Created by Bob on 6/25/2024.
//

#include "Observer.h"

void Subject::notifyAllObservervables() {
    for(auto o : this -> observerList)
        o->update();
}

void Subject::addObserver(Observer *obeserver) {
    this -> observerList.push_back(obeserver);
}
