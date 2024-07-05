#pragma once
#include <sqlite3.h>
#include "Repository.h"

class DBRepository : public Repository
{
private:
    sqlite3 *databaseWithMovies;
    std::string dataBaseName;

public:
    DBRepository(std::string dataBaseName);
    virtual ~DBRepository();
    void loadMoviesInRepository();
    void addMovie(Movie);
    void deleteMovie(std::string &movieName);
    void updateMovie(Movie updatedMovie);
    void saveMoviesFromRepository();
    string getFileName();
};