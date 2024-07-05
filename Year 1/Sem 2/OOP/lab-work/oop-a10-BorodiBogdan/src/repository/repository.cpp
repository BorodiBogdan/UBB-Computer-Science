#include "../../includes/repository/repository.h"

Repository::Repository()
{
    this->listOfMovies= vector<Movie>();
}

void Repository::addMovie(Movie movieToBeAdded)
{
    if (find(this->listOfMovies.begin(), this->listOfMovies.end(), movieToBeAdded) != this->listOfMovies.end())
        throw DuplicateMovieException();

    this->listOfMovies.push_back(movieToBeAdded);
    this->saveMoviesFromRepository();
}

void Repository::deleteMovie(std::string &movieName)
{
    int pos = -1, posWatch = -1;
    Utils::trimWhiteSpaces(movieName);
    // deleting from the list
    for (auto movie : listOfMovies)
        if (movie.getTitle() == movieName)
            pos = find(listOfMovies.begin(), listOfMovies.end(), movie) - listOfMovies.begin();

    if (pos == -1)
        throw RepositoryException("Movie not found for delete!");

   this->listOfMovies.erase(pos + listOfMovies.begin());
    // deleting it from watch list

    this->saveMoviesFromRepository();
}

void Repository::updateMovie(Movie updatedMovie)
{
    bool ok = 0;

    // updating the list of movies
    for (auto &movie : listOfMovies)
        if (movie.getTitle() == updatedMovie.getTitle())
            movie = updatedMovie,
            ok = 1;

    if (!ok)
        throw RepositoryException("No movie found for update");

    this->saveMoviesFromRepository();
}

vector<Movie> Repository::getListOfMovies() const
{
    return this->listOfMovies;
}
bool Repository::checkIfMovieIsInRepository(Movie movie)
{
    return find(this->listOfMovies.begin(), this->listOfMovies.end(), movie) != this->listOfMovies.end();
}
Movie Repository::getMovie(std::string name)
{
    Movie a;

    // deleting from the list
    for (auto movie : listOfMovies)
        if (movie.getTitle() == name)
            return movie;

    return Movie();
}