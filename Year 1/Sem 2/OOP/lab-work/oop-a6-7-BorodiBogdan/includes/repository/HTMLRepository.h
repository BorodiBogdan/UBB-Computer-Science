#pragma once
#include "repository.h"

class HTMLMovieRepository : public Repository
{
private:
    string HTMLFilePath;

public:
    HTMLMovieRepository();
    HTMLMovieRepository(string HTMLFilePath);
    void saveMoviesFromRepository();
    void loadMoviesInRepository();
    string getFileName();
};