#pragma once
#include "../repository/repository.h"
#include "../repository/undoRedoRepo.h"

typedef struct
{
    repository *Repo;
    undoRedoRepository *undoRedoRepo;

} Controller;

/*
No params
We create a new controller
*/
Controller *createController();

/*
param service: Controller *
We destroy the controller
*/
void DestroyController(Controller *service);

/*
param service: Controller *
We get the list of elements from the controller
*/
dynamicVector *getListOfElementsController(Controller *service);

/*
param service: Controller *
param Elem: Medicine *
We add a new element to the controller
*/
int addElementsController(Controller *service, Medicine *Elem);

/*
param service: Controller *
We get the size of the controller
*/
int getSizeController(Controller *service);

/*
param service: Controller *
param Elem: Medicine *
We update a medicine from the controller
*/
int updateMedicineController(Controller *service, Medicine *Elem);

/*
param service: Controller *
param name: char *
param concentration: int
We delete a medicine from the controller having the name and concentration, if the medicine is not found we return an error
*/
int deleteMedicineController(Controller *service, char *name, int concentration);

/*
param service: Controller *
param string: char *
We get all medicines that contain a string
*/
dynamicVector *getMedicinesByStringController(Controller *service, char *string);

/*
param service: Controller *
param numberOfEntries: int
We generate a number of entries
We have a list of meds names and we choose random a name from here
We also choose a random concentration, quantity and price
We add the medicine to the controller
We repeat this process numberOfEntries times
*/
void generateEntries(Controller *service, int numberOfEntries);

/*
param service: Controller *
We get the list of medicines that have the quantity smaller than a given value
*/
dynamicVector *getShortSupplyMedicines(Controller *service, int supplyValue);

/*
param service: Controller *
We undo the last operation
*/
int undoController(Controller *service);

/*
param service: Controller *
We redo the last operation
*/
int redoController(Controller *service);

/*
param service: Controller *
We sort the medicines in increasing order
return: dynamicVector *listOfMedicines -> the list of medicines sorted in increasing order
*/
dynamicVector *sortMedicinesIncreasing(dynamicVector *listOfMedicines);

/*
param service: Controller *
We sort the medicines in decreasing order
return: dynamicVector *listOfMedicines -> the list of medicines sorted in decreasing order
*/
dynamicVector *sortMedicinesDecreasing(dynamicVector *listOfMedicines);

/*
param service: Controller *
return: dynamicVector *listOfMedicines -> the list of medicines from the controller
*/
dynamicVector *getDynamicVectorController(Controller *service);

/*
param service: Controller *
return: dynamicVector *listOfMedicines -> the list of medicines that have the price smaller than a given value
*/
dynamicVector *getMedicinesCheaperThenX(Controller *service, int priceValue);