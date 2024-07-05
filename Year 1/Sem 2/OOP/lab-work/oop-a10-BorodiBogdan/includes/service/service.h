#pragma once
#include "../UndoRedoService/UndoRedoService.h"

class Service
{
protected:
    Repository *movieListRepository;
    Repository *watchListRepository;
    UndoRedoService *undoRedoService;

public:
    /*
    constructor for the Service class
    initializes the Service class

    */
    Service();

    /*
    void generateEntries(int numberOfEntries) - generates a number of entries
    @param numberOfEntries - the number of entries to be generated
    we generate a number of movies
    */
    void generateEntries(int numberOfEntries);

    /*
    vector<Movie> getMovies() - returns the list of movies
    we return the list of movies
    */
    vector<Movie> getMovies() const;

    /*
    parama @genre -> the genre of the movie
    reuturns the list of movies matching the genre, or the full list if the genre is not matching
    */
    vector<Movie> getMoviesByGenre(std::string genre);

    /*
    param @movie MovieToBeAdded
    Adds a movie to watchList and updates the number of likes
    */
    void addMovieToWatchList(Movie movieToBeAdded);

    /*
    return - Watch list
    */
    vector<Movie> getWatchList();

    /*
    return: true - movie is in watch list
            false - movie is not in watch list
    */
    bool checkIfMovieIsInWatchList(Movie movie);

    /*
    deletes a movie from the watch list
    return true if deletion is succesful, false otherwise
    */
    void deleteMovieFromWatchList(std::string movieTitle);

    /*
    bool deleteMovie(std::string movieName) - deletes a movie from the list of movies
    @param movieName - the name of the movie to be deleted
    returns true if the movie was deleted successfully, false otherwise
    */
    void deleteMovie(std::string movieName);

    /*
    bool addMovie(Movie movieToBeAdded) - adds a movie to the list of movies
    @param movieToBeAdded - the movie to be added
    returns true if the movie was added successfully, false otherwise
    */
    void addMovie(Movie movieToBeAdded);

    /*
    bool updateMovie(Movie movieToBeUpdated) - updates a movie from the list of movies
    @param movieToBeUpdated - the movie to be updated
    returns true if the movie was updated successfully, false otherwise
    */
    void updateMovie(Movie &movieToBeUpdated);
    /*
    gets a movie from the movie list
    */
    Movie getMovie(std::string movie);

    void setTypeOfRepo(string type);

    void setTypeOfDataBase(int option);

    void openWatchList();

    void executeUndo();

    void executeRedo();
};