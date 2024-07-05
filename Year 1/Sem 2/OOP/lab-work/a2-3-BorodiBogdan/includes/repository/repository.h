#pragma once
#include "../domain/domain.h"
#include "../domain/dynamicVector.h"
typedef struct
{
    dynamicVector *listOfMedicines;
} repository;

/*
We create a repository
param capacity: int
returns: repository * with the given capacity
*/
repository *createRepo(int capacity);

/*
We destroy the repository
*/
void deleteRepo(repository *repo);

/*
param repo: repository *
param elem: Medicine *
We add a new element to the repository
*/
int addMedicineToRepo(repository *repo, Medicine *elem);

/*
param repo: repository *
We get the list of elements from the repository
returns: dynamicVector * with the list of elements
*/
dynamicVector *getMedicinesFromRepo(repository *repo);

/*
param repo: repository *
We get the size of the repository
returns: int with the size of the repository
*/
int getSize(repository *repo);

/*
param repo: repository *
param name: char *
param concentration: int
We delete a medicine from the repository having the name and concentration, if the medicine is not found we return an error
returns: 1 if the medicine was deleted, Error otherwise
*/
int deleteMedicineRepo(repository *repo, char *name, int concentration);

/*
param repo: repository *
param elem: Medicine *
We update a medicine from the repository
returns: 1 if the medicine was updated, Error otherwise
*/
int updateMedicineRepo(repository *repo, Medicine *elem);

/*
param repo: repository *
We create a copy of the repository
returns: a new repository * with the same elements as the given repository
*/
repository *copyRepo(repository *repo);

/*
param repo: repository *
We destroy the repository
We created this function in order to use it in the undoRedoRepository, because we need to pass a void * to the removeDynamicVector function
and we can't pass a repository * to it
*/
void destroyRepositoryWrapper(void *repo);

/*
param repo: repository *
We get the dynamicVector from the repository
*/
dynamicVector *getDynamicVectorRepo(repository *repo);