#ifndef INC_1ST_QT_PROJECT_REPOSITORY_H
#define INC_1ST_QT_PROJECT_REPOSITORY_H
#include "department.h"
#include "volunteer.h"
#include <fstream>
#include "utils.h"

class repository {
private:
    vector<department> departments;
    vector<volunteer> volunteers;
    void readFromFile();
public:
    repository();
    vector<department> getDepartments() const;
    vector<volunteer> getVolunteers() const;
};


#endif //INC_1ST_QT_PROJECT_REPOSITORY_H
