#include "../../includes/repository/FileRepository.h"

FileRepository::FileRepository(string filePathForMovieList)
{
    this->filePathForMovieList = filePathForMovieList;
    this->loadMoviesInRepository();
}
void FileRepository::loadMoviesInRepository()
{

    string separator;
    ifstream readMovies(this->filePathForMovieList);

    vector<Movie> movieList;

    while (true)
    {
        Movie movieToBeAdded;

        try
        {
            readMovies >> movieToBeAdded;
        }
        catch (MovieExceptions &e)
        {

            break;
        }

        this->listOfMovies.push_back(movieToBeAdded);
    }
    readMovies.close();
}

void FileRepository::saveMoviesFromRepository()
{
    ofstream writeMovies(this->filePathForMovieList);

    for (auto movie : this->listOfMovies)
        writeMovies << movie;

    writeMovies.close();
}

string FileRepository::getFileName()
{
    return this->filePathForMovieList;
}