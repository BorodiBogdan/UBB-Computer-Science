#include "../../includes/repository/undoRedoRepo.h"
#include <stdio.h>

undoRedoRepository *createUndoRedoRepository()
{
    undoRedoRepository *newUndoRedoRepo = (undoRedoRepository *)malloc(sizeof(undoRedoRepository));
    newUndoRedoRepo->redoList = createDynamicVector(20);
    newUndoRedoRepo->undoList = createDynamicVector(20);

    return newUndoRedoRepo;
}
void destroyUndoRedoRepository(undoRedoRepository *undoRedoRepo)
{
    removeDynamicVector(undoRedoRepo->redoList, destroyRepositoryWrapper);
    removeDynamicVector(undoRedoRepo->undoList, destroyRepositoryWrapper);
    free(undoRedoRepo);
}
repository *performUndoOperation(undoRedoRepository *undoRepo, repository *currentState)
{
    if (getSizeOfDynamicVector(undoRepo->undoList) > 0)
    {
        dynamicVector *undoElements = undoRepo->undoList;
        int sizeOfArray = getSizeOfDynamicVector(undoElements);
        repository *element = getElementOnPosition(undoElements, sizeOfArray - 1);
        repository *returnedElement = element = copyRepo(element);

        addElementToDynamicVector(undoRepo->redoList, currentState);                             // we add it to redo
        deleteElementFromDynamicVector(undoElements, sizeOfArray - 1, destroyRepositoryWrapper); // we delete

        return returnedElement;
    }
    else
        return NULL;
}
repository *performRedoOperation(undoRedoRepository *undoRepo, repository *currentState)
{
    if (getSizeOfDynamicVector(undoRepo->redoList) > 0)
    {
        dynamicVector *redoElements = undoRepo->redoList;
        int sizeOfArray = getSizeOfDynamicVector(redoElements);
        repository *element = getElementOnPosition(redoElements, sizeOfArray - 1);
        element = copyRepo(element);

        addElementToDynamicVector(undoRepo->undoList, currentState);                             // we add it to undo
        deleteElementFromDynamicVector(redoElements, sizeOfArray - 1, destroyRepositoryWrapper); // we delete

        return element;
    }
    else
        return NULL;
}
void addOperation(undoRedoRepository *undoRepo, repository *repo)
{
    repository *newRepo = copyRepo(repo);
    addElementToDynamicVector(undoRepo->undoList, newRepo);
}