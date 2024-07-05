//
// Created by Bob on 6/28/2024.
//

#ifndef PRACTICAL_EXAM_OBSERVER_H
#define PRACTICAL_EXAM_OBSERVER_H
#include <vector>
using namespace std;

class Observer {
public:
    Observer() = default;
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class Subject{
private:
    vector<Observer *> obsList;
public:
    Subject() = default;
    void notify();
    virtual ~Subject() = default;
};


#endif //PRACTICAL_EXAM_OBSERVER_H
