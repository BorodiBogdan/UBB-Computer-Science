#include "ui.h"
#include <iostream>

void Ui::StartUi()
{
    cout << "1.Remove a school\n2.Show all schools\n3.Mark visited schools and retrieve non-visited schools\n0.Exit\n";
    this->service.addEntries();

    while (true)
    {
        int option;
        cin >> option;

        if (option == 1)
        {
            string schoolName;

            cout << "Enter school name:";
            cin >> schoolName;

            try
            {
                this->service.deleteSchool(schoolName);
            }
            catch (const char *e)
            {
                cout << e << "\n";
            }
        }
        if (option == 2)
        {
            vector<School> schoolList = this->service.getSchoolsListSortedByName();

            for (auto school : schoolList)
            {
                cout << school.getName() << " | " << school.getAddress() << " | " << school.getPlannedVisitDate() << " | ";
                if (school.getIsVisited() == true)
                    cout << "true\n";
                else
                    cout << "false\n";
            }
        }
        if (option == 3)
        {
            string date;

            cout << "Enter the date:";
            cin >> date;

            vector<School> schoolList = this->service.markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited(date);

            for (auto school : schoolList)
            {
                cout << school.getName() << " | " << school.getAddress() << " | " << school.getPlannedVisitDate() << " | ";
                if (school.getIsVisited() == true)
                    cout << "true\n";
                else
                    cout << "false\n";
            }
        }
        if (option == 0)
            break;
    }
}