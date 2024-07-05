#ifndef INC_1ST_QT_PROJECT_DEPARTMENT_H
#define INC_1ST_QT_PROJECT_DEPARTMENT_H
#include <string>
using namespace std;


class department {
private:
    string name, description;
public:
    department(string name, string description);
    string getName() const;
    string getDescription() const;
};


#endif //INC_1ST_QT_PROJECT_DEPARTMENT_H
