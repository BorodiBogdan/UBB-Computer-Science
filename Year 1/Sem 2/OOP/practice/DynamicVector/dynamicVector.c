#include "dynamicVector.h"
#include <stdlib.h>

dynamicVector *createDynamicVector(int capacity)
{
    dynamicVector *new_vector = (dynamicVector *)malloc(sizeof(dynamicVector));
    new_vector->listOfElements = (TElem *)malloc(sizeof(TElem) * capacity);
    new_vector->capacity = capacity;
    new_vector->size = 0;
    return new_vector;
}
void removeDynamicVector(dynamicVector *vector)
{
    free(vector->listOfElements);
    free(vector);
}
void resizeDynamicVector(dynamicVector *vector)
{
    vector->capacity *= 2;
    TElem *newListOfElements = (TElem *)realloc(vector->listOfElements, sizeof(TElem) * vector->capacity);

    if (newListOfElements == NULL)
        return;

    vector->listOfElements = newListOfElements;
}
void setDynamicVectorSize(dynamicVector *vector, int size)
{
    vector->size = size;
}
int getSizeOfDynamicVector(dynamicVector *vector)
{
    return vector->size;
}
int getCapacity(dynamicVector *vector)
{
    return vector->capacity;
}
TElem *getElements(dynamicVector *vector)
{
    return vector->listOfElements;
}
TElem getElementOnPosition(dynamicVector *vector, int position)
{
    if (position < 0 || position >= getSizeOfDynamicVector(vector))
        return NULL;

    TElem *vectorElements = getElements(vector);

    return vectorElements[position];
}
void deleteElementFromDynamicVector(dynamicVector *vector, int pos)
{
    if (pos < 0 || pos >= getSizeOfDynamicVector(vector))
        return;

    TElem *elementsOfVector = getElements(vector);

    for (int i = pos; i < getSizeOfDynamicVector(vector) - 1; ++i)
        elementsOfVector[i] = elementsOfVector[i + 1];

    setDynamicVectorSize(vector, getSizeOfDynamicVector(vector) - 1);
}
void addElementToDynamicVector(dynamicVector *vector, TElem element)
{
    if (getSizeOfDynamicVector(vector) + 1 > getCapacity(vector))
        resizeDynamicVector(vector);

    int size = getSizeOfDynamicVector(vector);
    TElem *elements = getElements(vector);
    elements[size] = element;

    setDynamicVectorSize(vector, size + 1);
}