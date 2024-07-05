#pragma once
#include "Person.h"
#include <iostream>

class Ui
{
private:
    Person person;

public:
    void runUi();
    void addMedicalAnalysis();
    static void printMenu();
};