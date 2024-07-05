#include "repository.h"
#include <cstring>
#include <qdebug.h>

vector<department> repository::getDepartments() const {
    return this -> departments;
}

vector<volunteer> repository::getVolunteers() const {
    return this -> volunteers;
}

void repository::readFromFile() {
    ifstream readVolunteers("volunteers.txt");
    ifstream readDepartments("departments.txt");

    string name, description;
    char line[256];

    while (readDepartments.getline(line, 256)) {
        qDebug() << QString::fromStdString(line);
        vector <char> delimiters = {'|'};
        utils u;
        string lineString = line;
        vector <string> departmentInfo = u.tokenize(delimiters, lineString);
        department newDepartment(departmentInfo[0], departmentInfo[1]);

        this -> departments.push_back(newDepartment);
    }

    while (readVolunteers.getline(line, 256)) {
        vector <char> delimiters = {'|'};
        vector <char> interestDelimiters = {','};
        utils u;

        vector<string> volunteerInfo = u.tokenize(delimiters, line);
        vector<string> interests = u.tokenize(interestDelimiters, volunteerInfo[2]);

        volunteer newVolunteer(volunteerInfo[0], volunteerInfo[1], interests, volunteerInfo[3]);
        qDebug() << QString::fromStdString(volunteerInfo[0]);
        this -> volunteers.push_back(newVolunteer);
    }

    readVolunteers.close();
    readDepartments.close();
}

repository::repository() {
    this -> readFromFile();
}
