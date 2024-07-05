#include "dynamicVector.h"
#include <stdio.h>
#include <stdlib.h>
#include "domain.h"

int main()
{
    void *x;

    dynamicVector *vector = createDynamicVector(20);

    int *p = malloc(10);

    for (int i = 0; i <= 20; ++i)
    {
        char *name = "nemele";
        Medicine *med = createMedicine(name, 50, 2, 3);
        addElementToDynamicVector(vector, med);
    }

    for (int i = 1; i <= 20; ++i)
        printf("%s\n", getMedicineName(getElementOnPosition(vector, i)));

    removeDynamicVector(vector);
    printf("Done!\n");
    return 0;
}