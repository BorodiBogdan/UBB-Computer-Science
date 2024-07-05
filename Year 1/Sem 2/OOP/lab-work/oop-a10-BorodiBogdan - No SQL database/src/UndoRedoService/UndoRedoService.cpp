//
// Created by Bob on 5/20/2024.
//

#include "includes//exceptions/Exceptions.h"
#include "includes/UndoRedoService/UndoRedoService.h"

addCommand::addCommand(Repository* movieRepository, Repository *watchListRepository, Movie argument) {
    this -> arguments.push_back(argument);
    this -> watchListRepository = watchListRepository;
    this -> movieRepository = movieRepository;
}

void addCommand::undo() {
    Movie movieToBeDeleted= arguments[0];
    string titleOfTheMovie = movieToBeDeleted.getTitle();

    this->movieRepository->deleteMovie(titleOfTheMovie);

    try{
        this -> watchListRepository->deleteMovie(titleOfTheMovie);
    }
    catch (RepositoryException &e){};
}

void addCommand::redo() {
    Movie movieToBeAdded = arguments[0];
    try {
        this->movieRepository->addMovie(movieToBeAdded);
    }
    catch (DuplicateMovieException &e){
        cout << e.what() << "\n";
    }
}

deleteCommand::deleteCommand(Repository*movieRepository, Repository *watchListRepository, Movie argument) {
    this -> arguments.push_back(argument);
    this -> watchListRepository = watchListRepository;
    this -> movieRepository = movieRepository;
}

void deleteCommand::undo() {
    Movie movieToBeAdded = arguments[0];
    this -> movieRepository->addMovie(movieToBeAdded);
}

void deleteCommand::redo() {
    Movie movieToBeDeleted= arguments[0];
    string titleOfTheMovie = movieToBeDeleted.getTitle();
    this -> movieRepository->deleteMovie(titleOfTheMovie);

    try{
        this -> watchListRepository->deleteMovie(titleOfTheMovie);
    }
    catch (RepositoryException &e){};
}

updateCommand::updateCommand(Repository*movieRepository, Repository *watchListRepository, Movie argumentBeforeUpdate, Movie argumentAfterUpdate) {
    this -> arguments.push_back(argumentBeforeUpdate);
    this -> arguments.push_back(argumentAfterUpdate);
    this -> watchListRepository = watchListRepository;
    this -> movieRepository = movieRepository;
}

void updateCommand::undo() {
    Movie movieBeforeUpdate = arguments[0];
    this->movieRepository->updateMovie(movieBeforeUpdate);

    try{
        this -> watchListRepository->updateMovie(movieBeforeUpdate);
    }
    catch (RepositoryException &e){};
}

void updateCommand::redo() {
    Movie movieAfterUpdate = arguments[1];
    this->movieRepository->updateMovie(movieAfterUpdate);

    try{
        this -> watchListRepository->updateMovie(movieAfterUpdate);
    }
    catch (RepositoryException &e){};
}

void UndoRedoService::addOperation(Command *lastCommand) {
    this -> undoStack.push(lastCommand);
}

void UndoRedoService::executeUndo() {
    if(undoStack.size() == 0)
        throw UndoRedoException("No more undos!!");

    Command *undoCommand = undoStack.top();
    undoCommand->undo();
    this->redoStack.push(undoCommand);
    undoStack.pop();
}

void UndoRedoService::executeRedo() {
    if(redoStack.size() == 0)
        throw UndoRedoException("No more redos!!");

    Command *redoCommand = redoStack.top();
    this->undoStack.push(redoCommand);
    redoCommand->redo();
    redoStack.pop();
}

Command::Command() {
    this->movieRepository = nullptr;
    this->watchListRepository = nullptr;
}
