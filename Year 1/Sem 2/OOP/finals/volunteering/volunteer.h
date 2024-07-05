//
// Created by Bob on 6/23/2024.
//

#ifndef INC_1ST_QT_PROJECT_VOLUNTEER_H
#define INC_1ST_QT_PROJECT_VOLUNTEER_H
#include <string>
#include <vector>
using namespace std;

class volunteer {
private:
    string name, email;
    vector<string> interests;
    string departmentName;
public:
    volunteer(string name, string email, vector<string> interests, string departmentName);
    string getName() const;
    string getEmail() const;
    vector<string> getInterests() const;
    string getDepartment() const;
};


#endif //INC_1ST_QT_PROJECT_VOLUNTEER_H
