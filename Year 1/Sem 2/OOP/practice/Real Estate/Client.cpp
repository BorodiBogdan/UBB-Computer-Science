#include "Client.h"

string Client::getName()
{
    return this->name;
}

double Client::totalIncome()
{
    return this->income;
}

string Client::toString()
{
    string returnString = "Name: " + this->name + "\nIncome: " + to_string(this->income) + "\nTotal income: " + to_string(this->totalIncome());

    return returnString;
}

Person::Person(string name, double income)
{
    this->name = name;
    this->income = income;
}

bool Person::isInterested(Dwelling d)
{
    return d.getPrice() / 1000 <= this->income;
}

Company::Company(string name, double income, double moneyFromInvestments)
{
    this->name = name;
    this->income = income;
    this->moneyFromInvestments = moneyFromInvestments;
}

double Company::totalIncome()
{
    return this->income + this->moneyFromInvestments;
}

string Company::toString()
{
    string returnString = "Name: " + this->name + "\nIncome: " + to_string(this->income) + "\nMoney from investments: ";
    returnString += to_string(this->moneyFromInvestments) + "\nTotal income: " + to_string(this->totalIncome());

    return returnString;
}

bool Company::isInterested(Dwelling d)
{
    return this->totalIncome() >= d.getPrice() / 100 && d.getIsProfitable() == true;
}
