#pragma once
#include "../controller/controller.h"

typedef struct
{
    Controller *service;
} Ui;

Ui *CreateUi();
void deleteUi(Ui *ui);
void startUi(Ui *ui);
void addMedicineUi(Ui *ui);
void displayAllMedicinesUi(Ui *ui);
void deleteMedicineUi(Ui *ui);
void updateMedicineUi(Ui *ui);
void displayMedicinesByAGivenString(Ui *ui);
void displayShortSupplyMedicinesUi(Ui *ui);
void undoUi(Ui *ui);
void redoUi(Ui *ui);
void sortElementsUi(Ui *ui);
void filterElementsByPriceUi(Ui *ui);