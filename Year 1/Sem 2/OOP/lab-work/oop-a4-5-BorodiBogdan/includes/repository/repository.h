#pragma once
#include "../domain/domain.h"
#include "../domain/dynamicVector.h"

class MovieRepository
{
private:
    DynamicVector<Movie> listOfMovies;
    DynamicVector<Movie> watchList;

public:
    /*
    Constructor for the MovieRepository class
    initializes the movieRepository class
    */
    MovieRepository();

    /*
    bool addMovie(Movie movieToBeAdded) - adds a movie to the list of movies
    @param movieToBeAdded - the movie to be added
    returns true if the movie was added successfully, false otherwise
    */
    bool addMovie(Movie movieToBeAdded);

    /*
    bool deleteMovie(std::string &movieName) - deletes a movie from the list of movies
    @param movieName - the name of the movie to be deleted
    returns true if the movie was deleted successfully, false otherwise
    */
    bool deleteMovie(std::string &movieName);

    /*
    bool updateMovie(Movie movieToBeDeleted) - updates a movie from the list of movies
    @param movieToBeDeleted - the movie to be updated
    returns true if the movie was updated successfully, false otherwise
    */
    bool updateMovie(Movie movieToBeDeleted);

    /*
    DynamicVector<Movie> getListOfMovies() - returns the list of movies
    */
    DynamicVector<Movie> getListOfMovies() const;

    /*
    Adds a movie to watch list
    param @Movie -> movie to be added
    */
    void addMovieToWatchListRepo(Movie movieToBeAdded);

    /*
    returns the watch list
    */
    DynamicVector<Movie> getWatchListRepo();

    /*
    Deletes a movie from watch list
    return true if succesfull, false otherwise
    */
    bool deleteMovieFromWatchList(std::string movieTitle);

    /*
    return true if a movie is in watch list
    false otherwise
    */
    bool checkIfMovieIsInWatchList(Movie movie);
    /*
    returns a movie from watch list
    */
    Movie getMovie(std::string name);
};