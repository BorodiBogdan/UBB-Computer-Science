#include <stdlib.h>
#include "../../includes/domain/dynamicVector.h"
#include <string.h>

dynamicVector *createDynamicVector(int capacity)
{
    dynamicVector *new_vector = (dynamicVector *)malloc(sizeof(dynamicVector));
    new_vector->listOfElements = (TElem *)malloc(sizeof(TElem) * capacity);
    new_vector->capacity = capacity;
    new_vector->size = 0;
    return new_vector;
}
void removeDynamicVector(dynamicVector *vector, DestroyElementFunctionPointer destroyElementFunction)
{
    if (vector == NULL)
        return;

    TElem *listOfElements = getElements(vector);

    for (int i = 0; i < getSizeOfDynamicVector(vector); ++i)
        destroyElementFunction(listOfElements[i]);

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
void deleteElementFromDynamicVector(dynamicVector *vector, int pos, DestroyElementFunctionPointer destroyFunct)
{
    if (pos < 0 || pos >= getSizeOfDynamicVector(vector))
        return;

    TElem *elementsOfVector = getElements(vector);
    void *elementToBeDeleted = elementsOfVector[pos];

    for (int i = pos; i < getSizeOfDynamicVector(vector) - 1; ++i)
        elementsOfVector[i] = elementsOfVector[i + 1];

    int size = getSizeOfDynamicVector(vector) - 1;
    destroyFunct(elementToBeDeleted);

    setDynamicVectorSize(vector, size);
}
void addElementToDynamicVector(dynamicVector *vector, TElem element)
{
    if (getSizeOfDynamicVector(vector) == getCapacity(vector))
        resizeDynamicVector(vector);

    int size = getSizeOfDynamicVector(vector);
    TElem *elements = getElements(vector);

    elements[size] = element;

    setDynamicVectorSize(vector, size + 1);
}
void updateElementDynamicVector(dynamicVector *vector, int pos, TElem elem)
{
    if (pos < 0 || pos >= getSizeOfDynamicVector(vector))
        return;

    vector->listOfElements[pos] = elem;
}
void swapElementsDynamicVector(dynamicVector *vector, int i, int j)
{
    TElem *elements = getElements(vector);
    TElem aux = elements[i];
    elements[i] = elements[j];
    elements[j] = aux;
}
dynamicVector *getCopyOfDynamicVector(dynamicVector *vector)
{
    dynamicVector *newVector = createDynamicVector(20);
    TElem *elements = getElements(vector);

    for (int i = 0; i < getSizeOfDynamicVector(vector); ++i)
        addElementToDynamicVector(newVector, elements[i]);

    return newVector;
}
int checkIfElementExiststs(dynamicVector *vector, TElem elem, CompareElementsFunctionPointer compareElementsFunction)
{
    for (int i = 0; i < getSizeOfDynamicVector(vector); ++i)
        if (compareElementsFunction(getElementOnPosition(vector, i), elem) == 1)
            return 1;

    return 0;
}