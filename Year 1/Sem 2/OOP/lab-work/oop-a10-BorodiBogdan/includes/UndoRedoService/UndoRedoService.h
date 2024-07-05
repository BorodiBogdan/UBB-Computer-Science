//
// Created by Bob on 5/20/2024.
//

#ifndef INC_1ST_QT_PROJECT_UNDOREDOSERVICE_H
#define INC_1ST_QT_PROJECT_UNDOREDOSERVICE_H
#include <vector>
#include <stack>
#include "../../includes/repository/repository.h"
#include "../../includes/repository/CSVRepository.h"
#include "../../includes/repository/HTMLRepository.h"
#include "../../includes/repository/DBRepository.h"
#include "../../includes/repository/FileRepository.h"

class Command{
protected:
    vector<Movie> arguments;
    Repository *movieRepository;
    Repository *watchListRepository;
public:
    Command();
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class addCommand : public Command{
public:
    addCommand(Repository*movieRepository, Repository *watchListRepository, Movie argument);
    void undo() override;
    void redo() override;
};

class deleteCommand : public Command{
public:
    deleteCommand(Repository*movieRepository, Repository *watchListRepository, Movie argument);
    void undo() override;
    void redo() override;
};

class updateCommand : public Command{
public:
    updateCommand(Repository*movieRepository, Repository *watchListRepository, Movie argumentBeforeUpdate, Movie argumentAfterUpdate);
    void undo() override;
    void redo() override;
};

class UndoRedoService{
private:
    stack<Command *> undoStack;
    stack<Command *>redoStack;
public:
    UndoRedoService() = default;
    void addOperation(Command *lastCommand);
    void executeUndo();
    void executeRedo();
};


#endif //INC_1ST_QT_PROJECT_UNDOREDOSERVICE_H
