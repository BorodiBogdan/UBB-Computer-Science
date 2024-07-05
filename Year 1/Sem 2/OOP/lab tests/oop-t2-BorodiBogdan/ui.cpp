#include "ui.h"
#include <iostream>

void Ui::addCar()
{
    int numberOfDoors;

    cout << "Number of doors: ";
    cin >> numberOfDoors;

    string engineType;

    cout << "Engine type: ";
    cin >> engineType;

    int autonomy = 0;

    if (engineType == "Electric")
    {
        cout << "Autonomy: ";
        cin >> autonomy;
    }

    this->service.addCar(numberOfDoors, engineType, autonomy);

    cout << "Car succesfully added:D\n_________________________\n"
         << this->service.getLastCar()->toString() << "\n";
}

void Ui::startUi()
{
    this->service.addEntries();

    while (true)
    {
        cout << "1.Add car\n2.Show all cars\n3.Save to file\n0.Exit\n";
        int option;
        cin >> option;

        if (option == 1)
            this->addCar();
        else if (option == 2)
        {
            vector<Car *> carList = this->service.getCars();

            for (auto car : carList)
                cout << car->toString() << "\n___________________\n";
        }
        else if (option == 3)
        {
            string fileName;
            cout << "File name: ";
            cin >> fileName;

            double price;
            cout << "Price: ";
            cin >> price;

            this->service.writeToFile(fileName, this->service.getCarsWithMaxPrice(price));
            cout << "Cars succesfully saved\n";
        }
        else if (option == 0)
        {
            cout << "Goodbye!!";
            exit(0);
        }
    }
}