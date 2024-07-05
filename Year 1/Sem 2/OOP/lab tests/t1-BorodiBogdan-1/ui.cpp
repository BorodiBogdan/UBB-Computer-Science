#include "ui.h"
#include <iostream>

void Ui::startUi()
{
    this->controller.addEntries();
    cout << "1.Add new school\n2.Show all the schools\n3.Show the 3 closest schools\n0.Exit\n";

    while (true)
    {
        int option;

        cin >> option;

        if (option == 1)
        {
            string name;
            float latitude;
            float longitude;
            string date;

            cout << "Enter name:";
            cin >> name;
            cout << "Enter latitude and longitude\n";
            cout << "Longitude:";
            cin >> longitude;
            cout << "Latidute:";
            cin >> latitude;
            cout << "Enter date:";
            cin >> date;

            School newSchool = School(name, latitude, longitude, date);

            try
            {
                this->controller.addNewSchool(newSchool);
            }
            catch (const char *e)
            {
                cout << e << "\n";
            }
        }
        else if (option == 2)
        {
            vector<School> schools = this->controller.getSchools();

            for (auto school : schools)
            {
                cout << school.getSchoolName() << " | " << school.getLongitude() << ", " << school.getLatitude() << " | " << school.getDateOfVisit() << "\n";
            }
        }
        else if (option == 0)
        {
            break;
        }
        else if (option == 3)
        {
            float latitude;
            float longitude;
            cout << "Enter longitude: ";
            cin >> longitude;
            cout << "Enter latitude: ";
            cin >> latitude;
            vector<School> EdistSchools = this->controller.getSchoolsSortedByEuclideanSpaceAndName(latitude, longitude);

            for (auto school : EdistSchools)
            {
                cout << school.getSchoolName() << " | " << school.getLongitude() << ", " << school.getLatitude() << " | " << school.getDateOfVisit() << "\n";
            }
        }
    }
}