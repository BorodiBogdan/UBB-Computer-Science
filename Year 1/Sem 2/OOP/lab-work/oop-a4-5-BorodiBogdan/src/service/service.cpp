#include "../../includes/service/service.h"
#include <iostream>

Service::Service()
{
    this->repository = MovieRepository();
}
void Service::generateEntries(int numberOfEntries)
{
    std::string movieList[] = {
        "The Shawshank Redemption",
        "The Godfather",
        "The Dark Knight",
        "Schindler's List",
        "Pulp Fiction",
        "The Lord of the Rings: The Return of the King",
        "Forrest Gump",
        "Inception",
        "The Matrix",
        "The Silence of the Lambs",
        "The Godfather: Part II",
        "The Green Mile",
        "Fight Club",
        "Goodfellas"};

    std::string movieGenres[] = {
        "Action",
        "Adventure",
        "Comedy",
        "Drama",
        "Fantasy",
        "Horror",
        "Mystery",
        "Romance",
        "Sci-Fi",
        "Thriller",
        "Animation",
        "Documentary",
        "Crime",
        "Historical",
        "War"};

    std::string movieUrls[] = {
        "https://www.youtube.com/watch?v=6hB3S9bIaco",
        "https://www.youtube.com/watch?v=sY1S34973zA",
        "https://www.youtube.com/watch?v=EXeTwQWrcwY",
        "https://www.youtube.com/watch?v=JdRGC-w9syA",
        "https://www.youtube.com/watch?v=Rrcc9EGGpIw",
        "https://www.youtube.com/watch?v=bLF6sAAMb4s",
        "https://www.youtube.com/watch?v=8hP9D6kZseM",
        "https://www.youtube.com/watch?v=vKQi3bBA1y8",
        "https://www.youtube.com/watch?v=WvlBTxPzjO4",
        "https://www.youtube.com/watch?v=qJr92K_hKl0",
        "https://www.youtube.com/watch?v=oaUJviG1Py4",
        "https://www.youtube.com/watch?v=SUXWAEX2jlg",
        "https://www.youtube.com/watch?v=7JwBf7xDRFI",
        "https://www.youtube.com/watch?v=V75dMMIW2B4"};

    for (int i = 0; i < numberOfEntries; ++i)
    {
        std::string movieName = movieList[i];
        std::string movieGenre = movieGenres[i];
        std::string movieTrailer = movieUrls[i];
        int movieLikes = rand() % 10000;
        int yearOfRelease = rand() % 70 + 1953;

        Movie movieToBeAdded = Movie(movieName, movieGenre, movieTrailer, yearOfRelease, movieLikes);

        this->repository.addMovie(movieToBeAdded);
    }
}

DynamicVector<Movie> Service::getMovies() const
{
    return this->repository.getListOfMovies();
}

DynamicVector<Movie> Service::getMoviesByGenre(std::string genre)
{
    DynamicVector<Movie> listOfMovies = this->getMovies();
    DynamicVector<Movie> searchedListOfMovies;

    for (int i = 0; i < listOfMovies.getSize(); i++)
        if (listOfMovies[i].getGenre() == genre)
            searchedListOfMovies.addElement(listOfMovies[i]);

    if (genre == "")
        return listOfMovies;

    return searchedListOfMovies;
}
void Service::addMovieToWatchList(Movie movieToBeAdded)
{
    this->repository.addMovieToWatchListRepo(movieToBeAdded);
}
DynamicVector<Movie> Service::getWatchList()
{
    return this->repository.getWatchListRepo();
}
bool Service::deleteMovieFromWatchList(std::string movieTitle)
{
    return this->repository.deleteMovieFromWatchList(movieTitle);
}
bool Service::addMovie(Movie movieToBeDeleted)
{
    return this->repository.addMovie(movieToBeDeleted);
}
bool Service::deleteMovie(std::string movieName)
{
    return this->repository.deleteMovie(movieName);
}

bool Service::updateMovie(Movie &movieToBeUpdated)
{
    return this->repository.updateMovie(movieToBeUpdated);
}
bool Service::checkIfMovieIsInWatchList(Movie movie)
{
    return this->repository.checkIfMovieIsInWatchList(movie);
}
Movie Service::getMovie(std::string movie)
{
    return this->repository.getMovie(movie);
}