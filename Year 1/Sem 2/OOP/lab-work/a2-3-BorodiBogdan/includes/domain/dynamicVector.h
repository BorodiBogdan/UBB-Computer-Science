#include "domain.h"
#define TElem void *
#pragma once
typedef void (*DestroyElementFunctionPointer)(TElem);
typedef int (*CompareElementsFunctionPointer)(TElem, TElem);

typedef struct
{
    TElem *listOfElements;
    int size, capacity;
} dynamicVector;

/*
param capacity: int
We create a dynamicVector
returns: dynamicVector * with the given capacity
*/
dynamicVector *createDynamicVector(int capacity);

/*
param vector: dynamicVector *
param destroyElementFunction: DestroyElementFunctionPointer
We destroy the dynamicVector
*/
void removeDynamicVector(dynamicVector *vector, DestroyElementFunctionPointer destroyElementFunction);

/*
param vector: dynamicVector *
We resize the dynamicVector
*/
void resizeDynamicVector(dynamicVector *vector);

/*
param vector: dynamicVector *
param size: int
We set the size of the dynamicVector
*/
void setDynamicVectorSize(dynamicVector *vector, int size);

/*
param vector: dynamicVector *
We get the size of the dynamicVector
*/
int getSizeOfDynamicVector(dynamicVector *vector);

/*
param vector: dynamicVector *
We get the capacity of the dynamicVector(max number of elements that can be stored before a reallocation is needed)
*/
int getCapacity(dynamicVector *vector);

/*
param vector: dynamicVector *
We get the list of elements from the dynamicVector
returns: TElem * with the list of elements
*/
TElem *getElements(dynamicVector *vector);

/*
param vector: dynamicVector *
param position: int
We get the element from the dynamicVector on a given position
returns: TElem on the given position
*/
TElem getElementOnPosition(dynamicVector *vector, int position);

/*
param vector: dynamicVector *
param pos: int
param destroyFunct: DestroyElementFunctionPointer
We delete an element from the dynamicVector
*/
void deleteElementFromDynamicVector(dynamicVector *vector, int pos, DestroyElementFunctionPointer destroyFunct);

/*
param vector: dynamicVector *
param element: TElem
We add a new element to the dynamicVector
*/
void addElementToDynamicVector(dynamicVector *vector, TElem element);

/*
param vector: dynamicVector *
param pos: int
param elem: TElem
We update an element from the dynamicVector
*/
void updateElementDynamicVector(dynamicVector *vector, int pos, TElem elem);

/*
param vector: dynamicVector *
param i: int
param j: int
We swap two elements from the dynamicVector
*/
void swapElementsDynamicVector(dynamicVector *vector, int i, int j);

/*
param vector: dynamicVector *
We create a copy of the dynamicVector
returns: a new dynamicVector * with the same elements as the given dynamicVector
*/
dynamicVector *getCopyOfDynamicVector(dynamicVector *vector);

/*
Check if an element already exists in the dynamicVector
*/
int checkIfElementExiststs(dynamicVector *vector, TElem elem, CompareElementsFunctionPointer compareElementsFunction);