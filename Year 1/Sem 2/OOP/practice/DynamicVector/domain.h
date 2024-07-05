#pragma once
#include <stdlib.h>

typedef struct
{
    char *name;
    int concentration, quantity, price;
} Medicine;

Medicine *createMedicine(char *name, int concentration, int quantity, int price);
void destroyMedicine(Medicine *med);
char *getMedicineName(Medicine *med);