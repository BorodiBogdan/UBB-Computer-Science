#include "RealEstateAgency.h"
#include <fstream>

void RealEstateAgency::addClient(Client *c)
{
    this->clientList.push_back(c);
}

Dwelling RealEstateAgency::addDwelling(double price, bool isProfitable)
{
    Dwelling d = Dwelling(price, isProfitable);
    this->dwellingList.push_back(d);
    return d;
}

void RealEstateAgency::removeClient(string name)
{
    int pos = -1;
    for (int i = 0; i < clientList.size(); ++i)
        if (this->clientList[i]->getName() == name)
        {
            pos = i;
            break;
        }
    if (pos == -1)
        return;

    for (int i = pos; i < clientList.size() - 1; ++i)
        clientList[i] = clientList[i + 1];

    clientList.pop_back();
}

vector<Client *> RealEstateAgency::getInterestedClients(Dwelling d)
{
    vector<Client *> interestedClients;

    for (auto client : this->clientList)
        if (client->isInterested(d))
            interestedClients.push_back(client);

    return interestedClients;
}

void RealEstateAgency::writeToFile(string fileName)
{
    ofstream fout(fileName);

    for (auto client : this->clientList)
        fout << client->toString() << "\n_________________________\n";
}

void RealEstateAgency::addEntries()
{
    Client *c1 = new Person("Andrei", 200);
    Client *c2 = new Person("Mihai", 500);
    Client *c3 = new Company("NTT Data", 12312, 20);
    Client *c4 = new Company("Dedeman", 1000, 12312);

    this->addDwelling(300000, true);
    this->addClient(c1);
    this->addClient(c2);
    this->addClient(c3);
    this->addClient(c4);
}

vector<Client *> RealEstateAgency::getAllClients()
{
    return this->clientList;
}

vector<Dwelling> RealEstateAgency::getAllDwellings()
{
    return this->dwellingList;
}

RealEstateAgency::~RealEstateAgency()
{
    for (auto client : this->clientList)
        free(client);
}
