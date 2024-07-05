#pragma once
#include <stdlib.h>
#define Error -111111111

typedef struct
{
    char *name;
    int concentration, quantity, price;
} Medicine;

Medicine *createMedicine(char *name, int concentration, int quantity, int price);
void destroyMedicine(Medicine *med);
int getMedicineConcentration(Medicine *med);
int getMedicineQuantity(Medicine *med);
int getMedicinePrice(Medicine *med);
char *getMedicineName(Medicine *med);
void destroyMedicineWrapper(void *medicine);
int compareMedicines(void *med1, void *med2);