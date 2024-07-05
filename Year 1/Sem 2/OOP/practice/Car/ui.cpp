#include "ui.h"
#include <iostream>

void Ui::addCar()
{
    string bodyStyle, engineType;
    int autonomy = 0;

    cout << "Body style: ";
    cin >> bodyStyle;
    cout << "Engine type: ";
    cin >> engineType;

    if (engineType == "Electric")
    {
        cout << "Autonomy: ";
        cin >> autonomy;
    }

    this->service.addCar(bodyStyle, engineType, autonomy);

    cout << "Car added succesfully. Price: " << this->service.getLastAddedCarPrice() << "\n";
}

void Ui::runUi()
{
    cout << "1.Add car\n2.Show all cars\n3.Save to file\n0.Exit\n";
    this->service.generateEntries();

    while (true)
    {
        int option;
        cout << "Option: ";
        cin >> option;

        if (option == 0)
            exit(0);
        else if (option == 1)
            this->addCar();
        else if (option == 2)
        {
            vector<Car> carList = this->service.getCars();

            for (auto car : carList)
                cout << car.toString() << "\n_________________________________________\n";
        }
        else if (option == 3)
        {
            float price;
            cout << "Price: ";
            cin >> price;
            string fileName;
            cout << "File name:";
            cin >> fileName;

            this->service.saveCarsWithPriceLowerThen(price, fileName);
        }
    }
}