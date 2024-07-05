#include "../domain/dynamicVector.h"
#include "../repository/repository.h"

typedef struct
{
    dynamicVector *undoList;
    dynamicVector *redoList;
} undoRedoRepository;

/*
We create a repository for undo and redo operations
returns: undoRedoRepository *
*/
undoRedoRepository *createUndoRedoRepository();

/*
We destroy the undoRedoRepository
*/
void destroyUndoRedoRepository(undoRedoRepository *undoRedoRepo);

/*
param undoRepo: undoRedoRepository *
param currentState: repository *
We perform the undo operation
returns: repository * after the undo operation
*/
repository *performUndoOperation(undoRedoRepository *undoRepo, repository *currentState);

/*
param undoRepo: undoRedoRepository *
param currentState: repository *
We perform the redo operation
returns: repository * after the redo operation
*/
repository *performRedoOperation(undoRedoRepository *undoRepo, repository *currentState);

/*
param undoRepo: undoRedoRepository *
param repo: repository *
We add a new operation(repository in our case) to the undoRedoRepository
*/
void addOperation(undoRedoRepository *undoRepo, repository *repo);