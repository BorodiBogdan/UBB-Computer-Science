#include "ui.h"
#include <iostream>

void Ui::startUi()
{
    cout << "1.Remove client\n2.Show all clients and all dwellings\n"
         << "3.Add a dwelling\n4.Save all clients to a file\n0.Exit";
    this->realEstateAgency.addEntries();

    while (true)
    {
        int option;
        cout << "Option: ";
        cin >> option;

        if (option == 1)
        {
            string name;
            cout << "Name: ";
            cin >> name;

            this->realEstateAgency.removeClient(name);
        }
        else if (option == 2)
        {
            vector<Client *> clientList = this->realEstateAgency.getAllClients();
            vector<Dwelling> dwellingList = this->realEstateAgency.getAllDwellings();

            cout << "Client list:\n";

            for (auto client : clientList)
                cout << client->toString() << "\n________________________________\n";

            cout << "Dwelling list:\n";

            for (auto dwelling : dwellingList)
                cout << dwelling.toString() << "\n________________________________\n";
        }
        else if (option == 3)
        {
            double price;
            bool isProfitable;
            cout << "Price: ";
            cin >> price;
            cout << "Is profitable: ";
            cin >> isProfitable;

            Dwelling d = this->realEstateAgency.addDwelling(price, isProfitable);

            vector<Client *> clientList = this->realEstateAgency.getInterestedClients(d);

            if (clientList.size() == 0)
                cout << "No interested clients\n";
            else
                for (auto client : clientList)
                    cout << client->toString() << "\n________________________________\n";
        }
        else if (option == 4)
        {
            string fileName;
            cout << "File name: ";
            cin >> fileName;
            this->realEstateAgency.writeToFile(fileName);
        }
        else if (option == 0)
            exit(0);
    }
}