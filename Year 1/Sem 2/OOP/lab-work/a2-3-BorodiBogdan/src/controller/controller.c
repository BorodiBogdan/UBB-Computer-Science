#include <string.h>
#include "../../includes/controller/controller.h"

Controller *createController()
{
    Controller *newController = (Controller *)malloc(sizeof(Controller));
    newController->Repo = createRepo(20);
    newController->undoRedoRepo = createUndoRedoRepository();

    return newController;
}
void DestroyController(Controller *service)
{
    deleteRepo(service->Repo);
    destroyUndoRedoRepository(service->undoRedoRepo);
    free(service);
}
dynamicVector *getListOfElementsController(Controller *service)
{
    return getMedicinesFromRepo(service->Repo);
}
int addElementsController(Controller *service, Medicine *Elem)
{
    repository *currentRepo = copyRepo(service->Repo);
    int op = addMedicineToRepo(service->Repo, Elem);
    ;

    if (op == Error)
    {
        deleteRepo(currentRepo);
        destroyMedicine(Elem);
        return Error;
    }

    addOperation(service->undoRedoRepo, currentRepo);
    deleteRepo(currentRepo);

    return 1;
}
int getSizeController(Controller *service)
{
    return getSize(service->Repo);
}
dynamicVector *getDynamicVectorController(Controller *service)
{
    return getDynamicVectorRepo(service->Repo);
}
int deleteMedicineController(Controller *service, char *name, int concentration)
{
    repository *currentRepo = copyRepo(service->Repo);
    int op = deleteMedicineRepo(service->Repo, name, concentration);

    if (op == Error)
    {
        deleteRepo(currentRepo);
        return Error;
    }

    addOperation(service->undoRedoRepo, currentRepo);
    deleteRepo(currentRepo);

    return 1;
}
int updateMedicineController(Controller *service, Medicine *Elem)
{
    repository *currentRepo = copyRepo(service->Repo);
    int op = updateMedicineRepo(service->Repo, Elem);

    if (op == Error)
    {
        deleteRepo(currentRepo);
        return Error;
    }

    addOperation(service->undoRedoRepo, currentRepo);
    deleteRepo(currentRepo);

    return 1;
}
dynamicVector *sortMedicinesIncreasing(dynamicVector *listOfMedicines)
{
    for (int i = 0; i < getSizeOfDynamicVector(listOfMedicines); ++i)
        for (int j = i + 1; j < getSizeOfDynamicVector(listOfMedicines); ++j)
        {
            Medicine *leftElement = getElementOnPosition(listOfMedicines, i);
            Medicine *rightElement = getElementOnPosition(listOfMedicines, j);

            if (strcmp(leftElement->name, rightElement->name) > 0)
            {
                swapElementsDynamicVector(listOfMedicines, i, j);
            }
        }
    return listOfMedicines;
}
dynamicVector *sortMedicinesDecreasing(dynamicVector *listOfMedicines)
{
    for (int i = 0; i < getSizeOfDynamicVector(listOfMedicines); ++i)
        for (int j = i + 1; j < getSizeOfDynamicVector(listOfMedicines); ++j)
        {
            Medicine *leftElement = getElementOnPosition(listOfMedicines, i);
            Medicine *rightElement = getElementOnPosition(listOfMedicines, j);

            if (strcmp(leftElement->name, rightElement->name) < 0)
            {
                swapElementsDynamicVector(listOfMedicines, i, j);
            }
        }
    return listOfMedicines;
}
dynamicVector *getMedicinesByStringController(Controller *service, char *name)
{
    dynamicVector *listOfMedicines = getMedicinesFromRepo(service->Repo);
    dynamicVector *listOfSearchedMedicines = createDynamicVector(20);

    if (name[0] == 10 && strlen(name) == 1)
        for (int i = 0; i < getSizeOfDynamicVector(listOfMedicines); ++i)
            addElementToDynamicVector(listOfSearchedMedicines, getElementOnPosition(listOfMedicines, i));
    else
    {
        name[strlen(name) - 1] = 0;
        for (int i = 0; i < getSize(service->Repo); ++i)
        {
            Medicine *currentElement = getElementOnPosition(listOfMedicines, i);

            if (strstr(currentElement->name, name) != 0)
                addElementToDynamicVector(listOfSearchedMedicines, currentElement);
        }
    }

    listOfSearchedMedicines = sortMedicinesIncreasing(listOfSearchedMedicines);

    return listOfSearchedMedicines;
}
dynamicVector *getShortSupplyMedicines(Controller *service, int supplyValue)
{
    dynamicVector *listOfSearchedMedicines = createDynamicVector(20);
    dynamicVector *listOfMedicines = getListOfElementsController(service);

    for (int i = 0; i < getSize(service->Repo); ++i)
    {
        Medicine *element = getElementOnPosition(listOfMedicines, i);

        if (element->quantity < supplyValue)
            addElementToDynamicVector(listOfSearchedMedicines, element);
    }
    return listOfSearchedMedicines;
}
dynamicVector *getMedicinesCheaperThenX(Controller *service, int priceValue)
{
    dynamicVector *listOfSearchedMedicines = createDynamicVector(20);
    dynamicVector *listOfMedicines = getListOfElementsController(service);

    for (int i = 0; i < getSize(service->Repo); ++i)
    {
        Medicine *element = getElementOnPosition(listOfMedicines, i);

        if (element->quantity < priceValue)
            addElementToDynamicVector(listOfSearchedMedicines, element);
    }
    return listOfSearchedMedicines;
}
void generateEntries(Controller *service, int numberOfEntries)
{
    char medicineName[][50] = {"Paracetamol",
                               "Ibuprofen",
                               "Aspirin",
                               "Nurofen",
                               "Doliprane",
                               "Naproxen",
                               "Diclofenac",
                               "Voltaren",
                               "Cataflam",
                               "Celebrex",
                               "Dolgit",
                               "Dolocordralan",
                               "Dolormin",
                               "Dolotren",
                               "Dolovisano",
                               "Doloxene",
                               "Doxylin",
                               "Panadol",
                               "Bisoprolol",
                               "Gabapentin",
                               "Kevzara",
                               "Zubsolv",
                               "Xanax",
                               "Hydroxychloroquine",
                               "Methadone"};

    for (int i = 0; i < numberOfEntries; i++)
    {
        int nameIndex = rand() % 26;
        int concentration = rand() % 1000;
        int quantity = rand() % 1000;
        int price = rand() % 1000;
        Medicine *medicine = createMedicine(medicineName[nameIndex], concentration, quantity, price);
        addMedicineToRepo(service->Repo, medicine);
    }
}
int undoController(Controller *service)
{
    repository *currentRepoState = performUndoOperation(service->undoRedoRepo, service->Repo);

    if (currentRepoState == NULL)
        return -1;

    service->Repo = currentRepoState;

    return 1;
}
int redoController(Controller *service)
{
    repository *currentRepoState = performRedoOperation(service->undoRedoRepo, service->Repo);

    if (currentRepoState == NULL)
        return -1;

    service->Repo = currentRepoState;

    return 1; // we succeded
}