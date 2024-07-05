#include "ui.h"

void Ui::addMedicalAnalysis()
{
    string type;
    string date;
    cout << "Enter analysis type: ";
    cin >> type;
    cout << "date:";
    cin >> date;

    if (type == "BP")
    {
        int systolic, diastolic;
        cout << "systolic: ";
        cin >> systolic;
        cout << "diastolic: ";
        cin >> diastolic;
        MedicalAnalysis *bp = new BP(systolic, diastolic, date);
        this->person.addAnalysis(bp);
    }
    else
    {
        float value;
        cout << "value: ";
        cin >> value;
        MedicalAnalysis *bmi = new BMI(date, value);
        this->person.addAnalysis(bmi);
    }
}

void Ui::runUi()
{
    printMenu();

    this->person.addAnalysis(new BP(50, 50, "2004.11.24"));
    this->person.addAnalysis(new BMI("2024.11.24", 30));

    while (true)
    {
        int option;
        cout << "Choose option: ";
        cin >> option;

        if (option == 1)
            this->addMedicalAnalysis();
        else if (option == 2)
        {
            vector<MedicalAnalysis *> analysesList = this->person.getAllAnalysis();

            for (auto analysis : analysesList)
                cout << analysis->toString() << "\n";
        }
        else if (option == 3)
        {
            int currentMonth;
            cout << "Current month: ";
            cin >> currentMonth;

            if (this->person.isIll(currentMonth))
                cout << "The person is ill!!!\n";
            else
                cout << "Not ill\n";
        }
        else if (option == 4)
        {
            cout << "File name: ";
            string fileName, date1, date2;
            cin >> fileName;

            cout << "Date 1: ";
            cin >> date1;
            cout << "Date 2:";
            cin >> date2;

            this->person.writeToFile(fileName, date1, date2);
        }
    }
}

void Ui::printMenu()
{
    cout << "1. Add new analysis\n2.Show all analyses\n"
         << "3.Show if the person is ill\n"
         << "4.Save to a file all the analyses between two given dates\n0.Exit";
}
