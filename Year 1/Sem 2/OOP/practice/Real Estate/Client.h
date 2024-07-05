#pragma once
#include "Dwelling.h"
#include <string>

class Client
{
protected:
    string name;
    double income;

public:
    string getName();
    virtual double totalIncome();
    virtual string toString();
    virtual bool isInterested(Dwelling d) = 0;
};

class Person : public Client
{
public:
    Person(string name, double income);
    bool isInterested(Dwelling d);
};

class Company : public Client
{
private:
    double moneyFromInvestments;

public:
    Company(string name, double income, double moneyFromInvestments);
    double totalIncome();
    string toString();
    bool isInterested(Dwelling d);
};