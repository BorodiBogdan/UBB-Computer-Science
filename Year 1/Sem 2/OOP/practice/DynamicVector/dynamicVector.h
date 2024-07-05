#define TElem void *
#pragma once

typedef struct
{
    TElem *listOfElements;
    int size, capacity;
} dynamicVector;

dynamicVector *createDynamicVector(int capacity);
void removeDynamicVector(dynamicVector *vector);
void resizeDynamicVector(dynamicVector *vector);
void setDynamicVectorSize(dynamicVector *vector, int size);
int getSizeOfDynamicVector(dynamicVector *vector);
int getCapacity(dynamicVector *vector);
TElem *getElements(dynamicVector *vector);
TElem getElementOnPosition(dynamicVector *vector, int position);
void deleteElementFromDynamicVector(dynamicVector *vector, int pos);
void addElementToDynamicVector(dynamicVector *vector, TElem element);
