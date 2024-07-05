//
// Created by Bob on 6/23/2024.
//

#ifndef INC_1ST_QT_PROJECT_SERVICE_H
#define INC_1ST_QT_PROJECT_SERVICE_H
#include "repository.h"

class service {
private:
    repository repo;
public:

    vector<department> getDepartments() const;
    vector<volunteer> getVolunteers() const;
};


#endif //INC_1ST_QT_PROJECT_SERVICE_H
