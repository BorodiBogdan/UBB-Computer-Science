//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_OBSERVER_H
#define INC_1ST_QT_PROJECT_OBSERVER_H
#include <vector>
using namespace std;

class Observer {
public:
    Observer() = default;
    virtual void update() = 0;
    ~Observer() = default;
};
class Subject {
private:
    vector<Observer*> observers;
public:
    Subject() = default;
    void addObserver(Observer* observer);
    void notify();
    ~Subject() = default;
};


#endif //INC_1ST_QT_PROJECT_OBSERVER_H
