#include "../../includes/service/service.h"
#include <iostream>

Service::Service()
{
    this->movieListRepository = new FileRepository("movieList.txt");
    this ->setTypeOfRepo("TXT");
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

        this->movieListRepository->addMovie(movieToBeAdded);
    }
}

vector<Movie> Service::getMovies() const
{
    return this->movieListRepository->getListOfMovies();
}

vector<Movie> Service::getMoviesByGenre(std::string genre)
{
    vector<Movie> listOfMovies = this->getMovies();
    vector<Movie> searchedListOfMovies;

    for (auto movie : listOfMovies)
        if (movie.getGenre() == genre)
            searchedListOfMovies.push_back(movie);

    if (genre == "")
        return listOfMovies;

    return searchedListOfMovies;
}
void Service::addMovieToWatchList(Movie movieToBeAdded)
{
    try {
        this->watchListRepository->addMovie(movieToBeAdded);
    }
    catch (DuplicateMovieException &e)
    {
        throw e;
    }
}
vector<Movie> Service::getWatchList()
{
    return this->watchListRepository->getListOfMovies();
}
void Service::deleteMovieFromWatchList(std::string movieTitle)
{
    try
    {
        this->watchListRepository->deleteMovie(movieTitle);
    }
    catch (RepositoryException &e)
    {
        throw e;
    }
}
void Service::addMovie(Movie movieToBeAdded)
{
    try
    {
        this->movieListRepository->addMovie(movieToBeAdded);

        addCommand *myAddCommand = new addCommand(this->movieListRepository, this->watchListRepository, movieToBeAdded);
        undoRedoService->addOperation(myAddCommand);
    }
    catch (DuplicateMovieException &e)
    {
        throw e;
    }
}
void Service::deleteMovie(std::string movieName)
{
    try
    {
        Movie movieToBeDeleted = this -> movieListRepository->getMovie(movieName);

        if(movieToBeDeleted.getTitle() != "" && movieToBeDeleted.getGenre() != ""){
            this->movieListRepository->deleteMovie(movieName);

            try
            {
                this->watchListRepository->deleteMovie(movieName);
            }
            catch (RepositoryException &e)
            {
            }

            deleteCommand *myRemoveCommand = new deleteCommand(this -> movieListRepository, this -> watchListRepository, movieToBeDeleted);
            undoRedoService->addOperation(myRemoveCommand);
        }
    }
    catch (RepositoryException &e)
    {
        throw e;
    }
}

void Service::updateMovie(Movie &movieToBeUpdated)
{
    try
    {
        Movie movieBeforeUpdate = this -> movieListRepository->getMovie(movieToBeUpdated.getTitle());

        this->movieListRepository->updateMovie(movieToBeUpdated);

        if (this->watchListRepository->checkIfMovieIsInRepository(movieToBeUpdated))
            this->watchListRepository->updateMovie(movieToBeUpdated);

        updateCommand *myUpdateCommand = new updateCommand(movieListRepository, watchListRepository, movieBeforeUpdate, movieToBeUpdated);
        undoRedoService->addOperation(myUpdateCommand);
    }
    catch (RepositoryException &e)
    {
        throw e;
    }
}
bool Service::checkIfMovieIsInWatchList(Movie movie)
{
    return this->watchListRepository->checkIfMovieIsInRepository(movie);
}
Movie Service::getMovie(std::string movie)
{
    return this->movieListRepository->getMovie(movie);
}
void Service::setTypeOfRepo(string type)
{
    if (type == "CSV")
        this->watchListRepository = new CSVRepository("watchList.csv");
    else if (type == "HTML")
        this->watchListRepository = new HTMLMovieRepository("watchList.html");
    else
        this->watchListRepository = new FileRepository("watchList.txt");
}

void Service::openWatchList()
{
    std::string commandToOpenFile = this->watchListRepository->getFileName();
    system(commandToOpenFile.c_str());
}
void Service::setTypeOfDataBase(int option)
{
    delete this->movieListRepository;

    try {
        if (option == 1)
            this->movieListRepository = new DBRepository("test.db");
        else
            this->movieListRepository = new FileRepository("movieList.txt");

        this -> undoRedoService = new UndoRedoService;
    }
    catch (RepositoryException &e)
    {
        throw e;
    }

}

void Service::executeUndo() {
    this ->undoRedoService->executeUndo();
}

void Service::executeRedo() {
    this -> undoRedoService->executeRedo();
}
