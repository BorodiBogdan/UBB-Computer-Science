#include "test.h"
#include <cassert>
#include <iostream>

void testAddService()
{
    Service service = Service();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovie(movie);
        assert(service.getMovies().size() == i);
        assert(service.getMovies()[i - 1].getTitle() == title);
    }
    assert(service.getMovies().size() == 100);
}

void testDeleteService()
{
    Service service = Service();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovie(movie);
    }
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        service.deleteMovie(title);
        assert(service.getMovies().size() == 100 - i);
    }
    assert(service.getMovies().size() == 0);
}

void testUpdateService()
{
    Service service = Service();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovie(movie);
    }
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        service.updateMovie(movie);
        assert(service.getMovies().size() == 100);
        assert(service.getMovies()[i - 1].getTitle() == title);
    }
    assert(service.getMovies().size() == 100);
}
void testGenerateEntriesService()
{
    Service service = Service();
    service.generateEntries(10);
    assert(service.getMovies().size() == 10);
}
void testAddRepository()
{
    MovieRepository repository = MovieRepository();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        repository.addMovie(movie);
        assert(repository.getListOfMovies().size() == i);
        assert(repository.getListOfMovies()[i - 1].getTitle() == title);
        try
        {
            repository.addMovie(movie);
        }
        catch (DuplicateMovieException e)
        {
            assert(true);
        }
    }
    assert(repository.getListOfMovies().size() == 100);
}
void testDeleteRepository()
{
    MovieRepository repository = MovieRepository();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        try
        {
            repository.deleteMovie(title);
            assert(false);
        }
        catch (RepositoryException &e)
        {
            assert(true);
        }
        assert(repository.deleteMovieFromWatchList(title) == Error);
        repository.addMovie(movie);
        repository.addMovieToWatchListRepo(movie);
    }
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        repository.deleteMovie(title);
        assert(repository.getListOfMovies().size() == 100 - i);
        assert(repository.getWatchListRepo().size() == 100 - i);
    }
    assert(repository.getListOfMovies().size() == 0);
}
void testUpdateRepository()
{
    MovieRepository repository = MovieRepository();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";

    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        try
        {
            repository.updateMovie(movie);
            assert(false);
        }
        catch (RepositoryException &e)
        {
            assert(true);
        }
        repository.addMovie(movie);
        repository.addMovieToWatchListRepo(movie);
    }
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        repository.updateMovie(movie);
        assert(repository.getListOfMovies().size() == 100);
        assert(repository.getListOfMovies()[i - 1].getTitle() == title);
        assert(repository.getWatchListRepo().size() == 100);
        assert(repository.getWatchListRepo()[i - 1].getTitle() == title);
    }
    assert(repository.getListOfMovies().size() == 100);
}
void testCreateRepository()
{
    MovieRepository repository = MovieRepository();
    assert(repository.getListOfMovies().size() == 0);
}
void testGetListOfMoviesRepository()
{
    MovieRepository repository = MovieRepository();
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        repository.addMovie(movie);
    }
    vector<Movie> vector = repository.getListOfMovies();
    assert(vector.size() == 100);
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        assert(vector[i - 1].getTitle() == title);
    }
}
void testGetTitleDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        title = "title";
        title += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        assert(movie.getTitle() == title);
        movie = movie;
    }
}
void testGetGenreDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        genre = "genre";
        genre += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        assert(movie.getGenre() == genre);
    }
}
void testGetTrailerDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        trailer = "trailer";
        trailer += std::to_string(i);
        Movie movie = Movie(title, genre, trailer, i, i);
        assert(movie.getTrailer() == trailer);
    }
}
void testGetYearDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        Movie movie = Movie(title, genre, trailer, i, i);
        assert(movie.getYearOfRelease() == i);
    }
}
void testGetLikesDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        Movie movie = Movie(title, genre, trailer, i, i);
        assert(movie.getNumberOfLikes() == i);
    }
}
void testSettersDomain()
{
    std::string title = "title";
    std::string genre = "genre";
    std::string trailer = "trailer";
    for (int i = 1; i <= 100; ++i)
    {
        Movie movie = Movie(title, genre, trailer, i, i);
        title = "title";
        title += std::to_string(i);
        genre = "genre";
        genre += std::to_string(i);
        trailer = "trailer";
        trailer += std::to_string(i);
        movie.setTitle(title);
        movie.setGenre(genre);
        movie.setTrailer(trailer);
        movie.setYearOfRelease(i);
        movie.setnumberOfLikes(i);
        assert(movie.getTitle() == title);
        assert(movie.getGenre() == genre);
        assert(movie.getTrailer() == trailer);
        assert(movie.getYearOfRelease() == i);
        assert(movie.getNumberOfLikes() == i);
    }
}
void testServiceCreate()
{
    Service service = Service();
    assert(service.getMovies().size() == 0);
    service = Service();
    assert(service.getMovies().size() == 0);
}
void testServiceGetWatchList()
{
    Service service = Service();
    assert(service.getWatchList().size() == 0);
    for (int i = 1; i <= 100; ++i)
    {
        std::string title = "title";
        title += std::to_string(i);
        std::string genre = "genre";
        std::string trailer = "trailer";
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovieToWatchList(movie);
        assert(service.getWatchList().size() == i);
        assert(service.getWatchList()[i - 1].getNumberOfLikes() == i);
    }
}
void testServiceAddMovieToWatchList()
{
    Service service = Service();
    assert(service.getWatchList().size() == 0);
    for (int i = 1; i <= 100; ++i)
    {
        std::string title = "title";
        title += std::to_string(i);
        std::string genre = "genre";
        std::string trailer = "trailer";
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovieToWatchList(movie);
        assert(service.checkIfMovieIsInWatchList((movie)) == true);
        assert(service.getWatchList().size() == i);
        assert(service.getWatchList()[i - 1].getNumberOfLikes() == i);
    }
}
void testServiceDeleteMovieFromWatchList()
{
    Service service = Service();
    assert(service.getWatchList().size() == 0);
    for (int i = 1; i <= 100; ++i)
    {
        std::string title = "title";
        title += std::to_string(i);
        std::string genre = "genre";
        std::string trailer = "trailer";
        Movie movie = Movie(title, genre, trailer, i, i);
        service.addMovieToWatchList(movie);
    }
    for (int i = 100; i >= 1; --i)
    {
        service.deleteMovieFromWatchList(service.getWatchList()[i - 1].getTitle());
        assert(service.getWatchList().size() == i - 1);
    }
    assert(service.getWatchList().size() == 0);
}
void testServiceGetMovieByGenre()
{
    Service service;
    assert(service.getMovies().size() == 0);
    for (int i = 1; i <= 100; ++i)
    {
        std::string title = "title";
        title += std::to_string(i);
        std::string genre = "genre";
        std::string trailer = "trailer";
        Movie movie = Movie(title, genre, trailer, i, i);

        service.addMovie(movie);
        service.addMovieToWatchList(movie);
    }

    assert(service.getMoviesByGenre("genre").size() == 100);
    assert(service.getMoviesByGenre("").size() == 100);
}

void testCreateService()
{
    Service service = Service();
    assert(service.getMovies().size() == 0);
    service.generateEntries(10);
    assert(service.getMovies().size() == 10);
}
void testAll()
{

    std::cout << "Tests are running...\n";
    std::cout << "Test add\n";
    testAddService();
    std::cout << "Test delete\n";
    testDeleteService();
    std::cout << "Test update\n";
    testUpdateService();
    std::cout << "Test generateEntries\n";
    testGenerateEntriesService();
    std::cout << "Test addRepository\n";
    testAddRepository();
    std::cout << "Test deleteRepository\n";
    testDeleteRepository();
    std::cout << "Test updateRepository\n";
    testUpdateRepository();
    std::cout << "Test createRepository\n";
    testCreateRepository();
    std::cout << "Test getListOfMoviesRepository\n";
    testGetListOfMoviesRepository();
    std::cout << "Test getTitleDomain\n";
    testGetTitleDomain();
    std::cout << "Test getGenreDomain\n";
    testGetGenreDomain();
    std::cout << "Test getTrailerDomain\n";
    testGetTrailerDomain();
    std::cout << "Test getYearDomain\n";
    testGetYearDomain();
    std::cout << "Test getLikesDomain\n";
    testGetLikesDomain();
    std::cout << "Test settersDomain\n";
    testSettersDomain();
    std::cout << "Test ServiceCreate\n";
    testServiceCreate();
    std::cout << "Test ServiceGetWatchList\n";
    testServiceGetWatchList();
    std::cout << "Test ServiceAddMovieToWatchList\n";
    testServiceAddMovieToWatchList();
    std::cout << "Test ServiceDeleteMovieFromWatchList\n";
    testServiceDeleteMovieFromWatchList();
    std::cout << "Test ServiceGetMovieByGenre\n";
    testServiceGetMovieByGenre();
    std::cout << "Test createService\n";
    testCreateService();
    std::cout << "All tests passed!\n";
}