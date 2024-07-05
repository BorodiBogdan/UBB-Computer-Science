#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "test.h"

void testAdd(Controller *service)
{
    int size = getSize(service->Repo);
    Medicine *med = createMedicine("Nurofen", 10, 5, 20);
    addElementsController(service, med);
    Medicine *med2 = createMedicine("Paracetamol", 10, 5, 20);
    addElementsController(service, med2);
    assert(getSize(service->Repo) == size + 2);
}
void testUpdate(Controller *service)
{
    int size = getSize(service->Repo);
    Medicine *med = createMedicine("Nurofen", 10, 5, 20);
    addElementsController(service, med);
    Medicine *med2 = createMedicine("Paracetamol", 10, 5, 20);
    addElementsController(service, med2);
    Medicine *med3 = createMedicine("Paracetamol", 10, 100, 7);
    updateMedicineController(service, med3);
    assert(getSize(service->Repo) == size + 2);
    assert(getMedicineQuantity(getElementOnPosition(getListOfElementsController(service), 1)) == 100);
}
void testRemove(Controller *service)
{
    int size = getSize(service->Repo);
    Medicine *med = createMedicine("Nurofen", 134, 5, 20);
    addElementsController(service, med);
    Medicine *med2 = createMedicine("Paracetamol", 13540, 5, 20);
    addElementsController(service, med2);

    deleteMedicineController(service, "Paracetamol", 13540);
    assert(getSize(service->Repo) == size + 1);

    for (int i = 1; i < 10; ++i)
    {
        Medicine *newMed = createMedicine("test", i + 100, 23, 21);
        addElementsController(service, newMed);
    }
    deleteMedicineController(service, "test", 213421);
    assert(getSize(service->Repo) == size + 10);
}
void testGenerateEntries(Controller *service)
{
    int size = getSize(service->Repo);
    generateEntries(service, 10);
    assert(getSize(service->Repo) == size + 10);
    generateEntries(service, 10);
    assert(getSize(service->Repo) == size + 20);
    generateEntries(service, 10);
    assert(getSize(service->Repo) == size + 30);
}
void testSort(Controller *service)
{
    dynamicVector *list = getListOfElementsController(service);
    sortMedicinesIncreasing(list);
    for (int i = 0; i < getSize(service->Repo) - 1; ++i)
    {
        Medicine *med1 = getElementOnPosition(list, i);
        Medicine *med2 = getElementOnPosition(list, i + 1);
        assert(strcmp(getMedicineName(med1), getMedicineName(med2)) <= 0);
    }
}
void testUndo(Controller *service)
{
    int size = getSize(service->Repo);
    Medicine *med = createMedicine("Nurofen", 213, 5, 20);
    addElementsController(service, med);
    Medicine *med2 = createMedicine("Paracetamol", 453, 5, 20);
    addElementsController(service, med2);
    undoController(service);
    assert(getSize(service->Repo) == size + 1);
    undoController(service);
    assert(getSize(service->Repo) == size);
}
void testRedo(Controller *service)
{
    int size = getSize(service->Repo);
    Medicine *med = createMedicine("Nurofen", 213, 5, 20);
    addElementsController(service, med);
    Medicine *med2 = createMedicine("Paracetamol", 453, 5, 20);
    addElementsController(service, med2);
    undoController(service);
    undoController(service);
    redoController(service);
    assert(getSize(service->Repo) == size + 1);
    redoController(service);
    assert(getSize(service->Repo) == size + 2);
}

void testAll(Ui *ui)
{
    testAdd(ui->service);
    printf("Test add passed...\n");
    testUpdate(ui->service);
    printf("Test update passed...\n");
    testRemove(ui->service);
    printf("Test remove passed...\n");
    testGenerateEntries(ui->service);
    printf("Test generate entries passed...\n");
    testSort(ui->service);
    printf("Test sort passed...\n");
    testUndo(ui->service);
    printf("Test undo passed...\n");
    testRedo(ui->service);
    printf("Test redo passed...\n");
    printf("...................\n");
    printf("All tests passed\n");
    deleteUi(ui);
}