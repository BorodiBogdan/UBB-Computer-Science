#include "../../includes/repository/repository.h"
#include <stdlib.h>
#include <string.h>

repository *createRepo(int capacity)
{
    repository *new_repo = (repository *)malloc(sizeof(repository));
    new_repo->listOfMedicines = createDynamicVector(capacity);

    return new_repo;
}
void deleteRepo(repository *repo)
{
    dynamicVector *ListOfMedicines = repo->listOfMedicines;

    if (ListOfMedicines != NULL)
        removeDynamicVector(ListOfMedicines, destroyMedicineWrapper);
    if (repo != NULL)
        free(repo);
}
int addMedicineToRepo(repository *repo, Medicine *elem)
{
    dynamicVector *listOfMedicines = repo->listOfMedicines;

    if (checkIfElementExiststs(listOfMedicines, elem, compareMedicines) == 0)
    {
        addElementToDynamicVector(listOfMedicines, elem);
        return 1;
    }
    return Error;
}
dynamicVector *getMedicinesFromRepo(repository *repo)
{
    return repo->listOfMedicines;
}
int getSize(repository *repo)
{
    return getSizeOfDynamicVector(repo->listOfMedicines);
}
int deleteMedicineRepo(repository *repo, char *name, int concentration)
{
    int pos = -1;

    int size = getSizeOfDynamicVector(repo->listOfMedicines);

    // we search for the element
    for (int i = 0; i < size; ++i)
    {
        Medicine *element = getElementOnPosition(repo->listOfMedicines, i);

        if (strcmp(name, element->name) == 0 && concentration == element->concentration)
            pos = i;
    }

    if (pos == -1)
        return Error;

    // we delete the element
    deleteElementFromDynamicVector(repo->listOfMedicines, pos, destroyMedicineWrapper);

    return 1;
}
int updateMedicineRepo(repository *repo, Medicine *Elem)
{
    char *name = Elem->name;
    int concentration = Elem->concentration;

    int size = getSize(repo);
    dynamicVector *listOfMedicines = repo->listOfMedicines;

    // we search for the element
    for (int i = 0; i < size; ++i)
    {
        Medicine *elementOnPosI = getElementOnPosition(listOfMedicines, i);

        if (strcmp(name, elementOnPosI->name) == 0 && concentration == elementOnPosI->concentration)
        {
            updateElementDynamicVector(listOfMedicines, i, Elem);
            destroyMedicineWrapper(elementOnPosI);
            return 1;
        }
    }
    return Error;
}
repository *copyRepo(repository *repo)
{
    repository *new_repo = createRepo(20);

    dynamicVector *listOfMedicines = getMedicinesFromRepo(repo);

    for (int i = 0; i < getSize(repo); ++i)
    {
        Medicine *prevMed = getElementOnPosition(listOfMedicines, i);

        Medicine *newMed = createMedicine(prevMed->name, prevMed->concentration, prevMed->quantity, prevMed->price);
        addMedicineToRepo(new_repo, newMed);
    }

    return new_repo;
}
dynamicVector *getDynamicVectorRepo(repository *repo)
{
    return repo->listOfMedicines;
}
void destroyRepositoryWrapper(void *repo)
{
    deleteRepo((repository *)repo);
}