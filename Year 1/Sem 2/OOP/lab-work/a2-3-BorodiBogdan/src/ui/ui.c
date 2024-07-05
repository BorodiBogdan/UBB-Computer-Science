#include "../../includes/ui/ui.h"
#include <string.h>
#include <stdio.h>

Ui *CreateUi()
{
    Ui *newUi = (Ui *)malloc(sizeof(Ui));
    newUi->service = createController();

    return newUi;
}
int readInteger()
{
    char input[50];
    scanf("%s", input);
    int result = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (!(input[i] >= '0' && input[i] <= '9'))
            return Error;

        result = result * 10 + (input[i] - '0');
    }

    return result;
}
void printListOfMedicines(dynamicVector *listOfMedicines)
{
    printf("\n\n");
    for (int i = 0; i < getSizeOfDynamicVector(listOfMedicines); ++i)
    {
        Medicine *element = getElementOnPosition(listOfMedicines, i);

        printf("Medicine number:  %d\n", i + 1);
        printf("\n");
        printf("Name: %s\n", element->name);
        printf("Concentration: %d\n", element->concentration);
        printf("Quantity: %d\n", element->quantity);
        printf("Price: %d\n", element->price);
        printf("___________________________________________\n");
    }
}
void deleteUi(Ui *ui)
{
    DestroyController(ui->service);
    free(ui);
}
void addMedicineUi(Ui *ui)
{
    char name[50];
    int price = 0, quantity = 0, concentration = 0;
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the concentration: ");
    concentration = readInteger();
    printf("Enter the quantity: ");
    quantity = readInteger();
    printf("Enter the price: ");
    price = readInteger();

    if (price == Error || quantity == Error || concentration == Error)
    {
        printf("Invalid input\n");
        return;
    }

    Medicine *elementToAdd = createMedicine(name, concentration, quantity, price);

    if (addElementsController(ui->service, elementToAdd) == Error)
        printf("Medicine already in\n");
    else
        printf("Medicine succesfully added!\n");
}
void displayAllMedicinesUi(Ui *ui)
{
    dynamicVector *listOfMedicines = getListOfElementsController(ui->service);

    printListOfMedicines(listOfMedicines);
}
void deleteMedicineUi(Ui *ui)
{
    char name[50];
    int concentration = 0;
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the concentration: ");
    concentration = readInteger();

    if (concentration == Error)
    {
        printf("Invalid input\n");
        return;
    }

    if (deleteMedicineController(ui->service, name, concentration) == Error)
        printf("Medicine not available\n");
}
void updateMedicineUi(Ui *ui)
{
    char name[50];
    int price = 0, quantity = 0, concentration = 0;

    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the concentration: ");
    concentration = readInteger();
    printf("Enter the new quantity: ");
    quantity = readInteger();
    printf("Enter the new price: ");
    price = readInteger();

    if (price == Error || quantity == Error || concentration == Error)
    {
        printf("Invalid input\n");
        return;
    }

    Medicine *elementToUpdate = createMedicine(name, concentration, quantity, price);

    if (updateMedicineController(ui->service, elementToUpdate) == Error)
    {
        printf("No medicine to update!!!\n");
        destroyMedicine(elementToUpdate);
    }
}
void displayMedicinesByAGivenString(Ui *ui)
{
    char medicineString[50];

    int character = 0;
    while ((character = getchar()) != '\n' && character != EOF)
        ;

    printf("Enter string:");
    fgets(medicineString, 50, stdin);
    dynamicVector *listOfSearchedMedicines = getMedicinesByStringController(ui->service, medicineString);

    if (getSizeOfDynamicVector(listOfSearchedMedicines) == 0)
    {
        printf("No medicines matching!!!!\n");
        free(listOfSearchedMedicines->listOfElements);
        free(listOfSearchedMedicines);
        return;
    }

    printListOfMedicines(listOfSearchedMedicines);

    free(listOfSearchedMedicines->listOfElements);
    free(listOfSearchedMedicines);
}
void displayShortSupplyMedicinesUi(Ui *ui)
{
    int supplyValue;
    printf("Enter the quantity: ");
    supplyValue = readInteger();

    if (supplyValue == Error)
    {
        printf("Invalid value!!!!\n");
        return;
    }

    dynamicVector *listOfSearchedMedicines = getShortSupplyMedicines(ui->service, supplyValue);

    if (getSizeOfDynamicVector(listOfSearchedMedicines) == 0)
    {
        printf("No medicines matching!!!!\n");
        free(listOfSearchedMedicines->listOfElements);
        free(listOfSearchedMedicines);
        return;
    }

    printListOfMedicines(listOfSearchedMedicines);

    free(listOfSearchedMedicines->listOfElements);
    free(listOfSearchedMedicines);
}
void sortElementsUi(Ui *ui)
{
    printf("1. Sort ascending\n");
    printf("2. Sort descending\n");

    int option = readInteger();

    if (option == Error)
    {
        printf("Invalid option for sorting!!\n");
        return;
    }

    dynamicVector *sortedElements = getCopyOfDynamicVector(getDynamicVectorController(ui->service));

    if (option == 1)
        sortedElements = sortMedicinesIncreasing(sortedElements);
    else if (option == 2)
        sortedElements = sortMedicinesDecreasing(sortedElements);
    else
    {
        printf("Invalid option!!!\n");
        free(sortedElements->listOfElements);
        free(sortedElements);
        return;
    }

    printListOfMedicines(sortedElements);

    free(sortedElements->listOfElements);
    free(sortedElements);
}
void filterElementsByPriceUi(Ui *ui)
{
    int priceValue;
    printf("Enter the quantity: ");
    priceValue = readInteger();

    if (priceValue == Error)
    {
        printf("Invalid value!!!!\n");
        return;
    }

    dynamicVector *listOfSearchedMedicines = getMedicinesCheaperThenX(ui->service, priceValue);

    if (getSizeOfDynamicVector(listOfSearchedMedicines) == 0)
    {
        printf("No medicines matching!!!!\n");
        free(listOfSearchedMedicines->listOfElements);
        free(listOfSearchedMedicines);
        return;
    }

    printListOfMedicines(listOfSearchedMedicines);

    free(listOfSearchedMedicines->listOfElements);
    free(listOfSearchedMedicines);
}
void undoUi(Ui *ui)
{
    int op = undoController(ui->service);

    if (op == -1)
        printf("No more undo's\n");
}
void redoUi(Ui *ui)
{
    int op = redoController(ui->service);

    if (op == -1)
        printf("No more redo's\n");
}
void startUi(Ui *ui)
{
    generateEntries(ui->service, 10);
    printf("Choose an option:\n");
    printf("1. Add medicine\n");
    printf("2. Delete medicine\n");
    printf("3. Update medicine\n");
    printf("4. Display all medicines\n");
    printf("5. Display medicines by a given string\n");
    printf("6. See only those medicines that are in short supply\n");
    printf("7. Undo\n");
    printf("8. Redo\n");
    printf("9. Display sorted elements\n");
    printf("10. Filter medicines by price\n");
    printf("0. exit program\n");

    while (1 > 0)
    {
        int option = 0;

        printf("Enter option: ");
        option = readInteger();

        if (option == Error)
            printf("Invalid input\n");

        if (option == 1)
            addMedicineUi(ui);
        else if (option == 2)
            deleteMedicineUi(ui);
        else if (option == 3)
            updateMedicineUi(ui);
        else if (option == 4)
            displayAllMedicinesUi(ui);
        else if (option == 5)
            displayMedicinesByAGivenString(ui);
        else if (option == 6)
            displayShortSupplyMedicinesUi(ui);
        else if (option == 7)
            undoUi(ui);
        else if (option == 8)
            redoUi(ui);
        else if (option == 9)
            sortElementsUi(ui);
        else if (option == 10)
            filterElementsByPriceUi(ui);
        else if (option == 0)
            return;
        else
            printf("Invalid option\n");
    }
}