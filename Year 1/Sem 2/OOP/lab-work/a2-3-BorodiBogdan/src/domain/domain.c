#include "../../includes/domain/domain.h"
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
    if (med->name != NULL)
        free(med->name);
    if (med != NULL)
        free(med);
}
int getMedicineConcentration(Medicine *med)
{
    return med->concentration;
}
int getMedicineQuantity(Medicine *med)
{
    return med->quantity;
}
int getMedicinePrice(Medicine *med)
{
    return med->price;
}
char *getMedicineName(Medicine *med)
{
    return med->name;
}
void destroyMedicineWrapper(void *medicine)
{
    destroyMedicine((Medicine *)medicine);
}
int compareMedicines(void *med1, void *med2)
{
    Medicine *medicine1 = (Medicine *)med1;
    Medicine *medicine2 = (Medicine *)med2;
    return medicine1->concentration == medicine2->concentration && strcmp(medicine1->name, medicine2->name) == 0;
}