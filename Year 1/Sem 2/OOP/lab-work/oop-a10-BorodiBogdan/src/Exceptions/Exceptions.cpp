#include "includes/exceptions/Exceptions.h"

FileException::FileException(const std::string &message)
{
    this->message = message;
}

const char *FileException::what()
{
    return this->message.c_str();
}

RepositoryException::RepositoryException() : std::exception()
{
    this->message = "";
}

RepositoryException::RepositoryException(const std::string &message)
{
    this->message = message;
}

const char *RepositoryException::what()
{
    return this->message.c_str();
}

const char *DuplicateMovieException::what()
{
    return "The movie is already in the repository!";
}

UndoRedoException::UndoRedoException(const std::string &message) {
    this->message = message;
}

const char *UndoRedoException::what() {
    return this->message.c_str();
}
