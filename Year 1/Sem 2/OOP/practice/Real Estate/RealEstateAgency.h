#pragma once
#include <string>
#include <vector>
#include "Client.h"

using namespace std;

class RealEstateAgency
{
private:
    vector<Dwelling> dwellingList;
    vector<Client *> clientList;
    void addClient(Client *c);

public:
    Dwelling addDwelling(double price, bool isProfitable);
    void removeClient(string name);
    vector<Client *> getInterestedClients(Dwelling d);
    void writeToFile(string fileName);
    void addEntries();
    vector<Client *> getAllClients();
    vector<Dwelling> getAllDwellings();
    ~RealEstateAgency();
};