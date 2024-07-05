#pragma once
#include "../domain/domain.h"
#include "../exceptions/Exceptions.h"
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Repository
{
protected:
    vector<Movie> listOfMovies;

public:
    /*
    Constructor for the Repository class
    initializes the Repository class
    */
    Repository();

    /*
    bool addMovie(Movie movieToBeAdded) - adds a movie to the list of movies
    @param movieToBeAdded - the movie to be added
    returns true if the movie was added successfully, false otherwise
    */
    virtual void addMovie(Movie movieToBeAdded);

    /*
    bool deleteMovie(std::string &movieName) - deletes a movie from the list of movies
    @param movieName - the name of the movie to be deleted
    returns true if the movie was deleted successfully, false otherwise
    */
    virtual void deleteMovie(std::string &movieName);

    /*
    bool updateMovie(Movie movieToBeDeleted) - updates a movie from the list of movies
    @param movieToBeDeleted - the movie to be updated
    returns true if the movie was updated successfully, false otherwise
    */
    virtual void updateMovie(Movie movieToBeDeleted);

    /*
    vector<Movie> getListOfMovies() - returns the list of movies
    */
    vector<Movie> getListOfMovies() const;
    /*
    return true if a movie is in watch list
    false otherwise
    */
    bool checkIfMovieIsInRepository(Movie movie);
    /*
    returns a movie from watch list
    */
    Movie getMovie(std::string name);

    virtual void loadMoviesInRepository() = 0;

    virtual void saveMoviesFromRepository() = 0;

    virtual string getFileName() = 0;

    virtual ~Repository() {};
};
