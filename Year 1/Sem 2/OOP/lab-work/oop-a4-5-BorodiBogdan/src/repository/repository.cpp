#include "../../includes/repository/repository.h"

MovieRepository::MovieRepository()
{
    this->listOfMovies = DynamicVector<Movie>();
    this->watchList = DynamicVector<Movie>();
}
bool MovieRepository::addMovie(Movie movieToBeAdded)
{
    if (this->listOfMovies.isElement(movieToBeAdded) == true)
        return Error;

    this->listOfMovies.addElement(movieToBeAdded);
    return 1;
}

bool MovieRepository::deleteMovie(std::string &movieName)
{
    int pos = -1, posWatch = -1;

    // deleting from the list
    for (int i = 0; i < this->listOfMovies.getSize(); ++i)
        if (this->listOfMovies[i].getTitle() == movieName)
            pos = i;

    // deleting it from watch list
    for (int i = 0; i < this->watchList.getSize(); ++i)
        if (this->watchList[i].getTitle() == movieName)
            posWatch = i;

    if (pos == -1)
        return Error;

    this->listOfMovies.deleteElement(pos);

    if (posWatch != -1)
        this->watchList.deleteElement(posWatch);

    return true;
}

bool MovieRepository::updateMovie(Movie updatedMovie)
{
    bool ok = 0;

    // updating the list of movies
    for (int i = 0; i < this->listOfMovies.getSize(); ++i)
        if (this->listOfMovies[i].getTitle() == updatedMovie.getTitle())
            this->listOfMovies[i] = updatedMovie,
            ok = 1;

    // updating watch list
    for (int i = 0; i < this->watchList.getSize(); ++i)
        if (this->watchList[i].getTitle() == updatedMovie.getTitle())
            this->watchList[i] = updatedMovie;

    if (!ok)
        return Error;

    return true;
}

DynamicVector<Movie> MovieRepository::getListOfMovies() const
{
    return this->listOfMovies;
}

void MovieRepository::addMovieToWatchListRepo(Movie movieToBeAdded)
{
    this->watchList.addElement(movieToBeAdded);
}
DynamicVector<Movie> MovieRepository::getWatchListRepo()
{
    return this->watchList;
}
bool MovieRepository::deleteMovieFromWatchList(std::string movieTitle)
{
    int posWatch = -1;

    // deleting it from watch list
    for (int i = 0; i < this->watchList.getSize(); ++i)
        if (this->watchList[i].getTitle() == movieTitle)
            posWatch = i;

    if (posWatch == -1)
        return Error;

    this->watchList.deleteElement(posWatch);

    return true;
}

bool MovieRepository::checkIfMovieIsInWatchList(Movie movie)
{
    return this->watchList.isElement(movie);
}
Movie MovieRepository::getMovie(std::string name)
{
    int pos = -1;

    // deleting from the list
    for (int i = 0; i < this->listOfMovies.getSize(); ++i)
        if (this->listOfMovies[i].getTitle() == name)
            pos = i;

    return this->listOfMovies[pos];
}