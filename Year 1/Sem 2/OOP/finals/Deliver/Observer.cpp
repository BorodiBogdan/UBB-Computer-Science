//
// Created by Bob on 6/28/2024.
//

#include "Observer.h"

void Subject::addObserver(Observer* observer){
    this -> observers.push_back(observer);
}
void Subject::notify(){
    for(auto &observer: this -> observers){
        observer -> update();
    }
}