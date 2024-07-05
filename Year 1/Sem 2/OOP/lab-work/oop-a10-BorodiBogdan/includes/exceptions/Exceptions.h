#pragma once
#include <string>
#include <vector>
#include <exception>

class UndoRedoException : public std::exception
{
private:
    std::string message;

public:
    UndoRedoException(const std::string &message);
    virtual const char *what();
};

class FileException : public std::exception
{
private:
  std::string message;

public:
  FileException(const std::string &message);
  virtual const char *what();
};

class RepositoryException : public std::exception
{
protected:
  std::string message;

public:
  RepositoryException();
  RepositoryException(const std::string &message);
  virtual ~RepositoryException(){};
  virtual const char *what();
};

class DuplicateMovieException : public RepositoryException
{
public:
  const char *what();
};
