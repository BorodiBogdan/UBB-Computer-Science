//
// Created by Bob on 6/25/2024.
//

#ifndef INC_1ST_QT_PROJECT_OBSERVER_H
#define INC_1ST_QT_PROJECT_OBSERVER_H
#include <vector>
#include <iostream>
using namespace std;

class Observer {
public:
    Observer() = default;
    virtual void update() = 0;
    ~Observer() = default;
};

class Subject{
protected:
    vector <Observer*> observerList;
public:
    Subject() = default;
    void notifyAllObservervables();
    void addObserver(Observer *obeserver);
    ~Subject() = default;
};


#endif //INC_1ST_QT_PROJECT_OBSERVER_H
