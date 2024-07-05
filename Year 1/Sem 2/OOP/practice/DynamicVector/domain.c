#include "domain.h"
#include <string.h>
#include <stdlib.h>

Medicine *createMedicine(char *name, int concentration, int quantity, int price)
{
    Medicine *new_medicine = (Medicine *)malloc(sizeof(Medicine));
    new_medicine->name = (char *)malloc(sizeof(char) * 50);
    strcpy(new_medicine->name, name);
    new_medicine->concentration = concentration;
    new_medicine->quantity = quantity;
    new_medicine->price = price;

    return new_medicine;
}
void destroyMedicine(Medicine *med)
{
    if (med->name)
        free(med->name);
    // free(med);
}
char *getMedicineName(Medicine *med)
{
    return med->name;
}
