#include "ui.h"
#include <iostream>

void Ui::addDepartment()
{
    cout << "1.Surgery\n2.Neonatal Unit\n";

    int option;

    cout << "Chose option: ";
    cin >> option;

    string name;
    cout << "Name: ";
    cin >> name;
    cout << "Number of doctors: ";
    int nrOfDoc;
    cin >> nrOfDoc;

    if (option == 1)
    {
        cout << "Number of patients: ";
        int nrOfPatients;
        cin >> nrOfPatients;

        HospitalDepartment *d = new Surgery(name, nrOfDoc, nrOfPatients);

        this->service.addDepartment(d);
    }
    else
    {
        cout << "Number of mothers: ";
        int nrOfMums;
        cin >> nrOfMums;
        cout << "Number of babies: ";
        int nrOfBabies;
        cin >> nrOfBabies;
        cout << "Average grade: ";
        double averageGrade;
        cin >> averageGrade;

        HospitalDepartment *d = new NeonatalUnits(name, nrOfDoc, nrOfMums, nrOfBabies, averageGrade);

        this->service.addDepartment(d);
    }
}

void Ui::runUi()
{
    cout << "1.Add new department\n2.Show all departments\n3.Show all the efficient departments\n4.Save to file\n0.Exit\n";
    this->service.addEntries();
    int option;

    while (true)
    {
        cout << "Choose option: ";
        cin >> option;

        if (option == 1)
            this->addDepartment();
        else if (option == 2)
        {
            vector<HospitalDepartment *> departmentList = this->service.getAllDepartments();

            for (auto department : departmentList)
                cout << department->toString() << "\n___________________________\n";
        }
        else if (option == 3)
        {
            vector<HospitalDepartment *> departmentList = this->service.getEfficientDepartments();

            for (auto department : departmentList)
                cout << department->toString() << "\n___________________________\n";
        }
        else if (option == 4)
        {
            string fileName;

            cout << "File name: ";
            cin >> fileName;

            this->service.writeToFile(fileName);
        }
        else if (option == 0)
            exit(0);
        else
            cout << "Invalid option\n";
    }
}