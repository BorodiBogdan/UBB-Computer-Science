#include "../../includes/ui/ui.h"
#include "../../tests/test.h"
#include <iostream>
#include <cassert>
#include <windows.h>

const std::string adminMode = "1";
const std::string userMode = "2";
const std::string Exit = "0";
const std::string addMovie = "1";
const std::string updateMovie = "2";
const std::string deleteMovie = "3";
const std::string displayAllMovies = "4";
const std::string printMoviesByGenre = "1";
const std::string like = "1";
const std::string next = "2";
const std::string deleteMovieFromWatchList = "2";
const std::string seeWatchList = "3";

Ui::Ui()
{
    this->service = Service();
};

void Ui::printInitialMenu()
{
    std::string displayedString = "\n";
    displayedString += "1. Admin mode\n";
    displayedString += "2. User mode\n";
    displayedString += "0. Exit\n";

    std::cout << displayedString;
}
void Ui::printAdminMenu()
{
    std::string displayedString = "\n";
    displayedString += "1. Add movie\n";
    displayedString += "2. Delete movie\n";
    displayedString += "3. Remove movie\n";
    displayedString += "4. Display movies\n";
    displayedString += "0. Back\n";

    std::cout << displayedString;
}
void Ui::printUserMenu()
{
    std::string displayedString = "\n";
    displayedString += "1. List all movies by genre\n";
    displayedString += "2. Delete a movie from the watch list\n";
    displayedString += "3. See the watch list\n";
    displayedString += "4. Print all movies\n";
    displayedString += "0. Back\n";

    std::cout << displayedString;
}
void Ui::deleteMovieFromWatchListUi()
{
    std::string movieTitle;
    std::cout << "Enter movie title: ";
    std::cin.get();
    getline(std::cin, movieTitle);

    try
    {

        if (this->service.deleteMovieFromWatchList(movieTitle) == Error)
            throw std::exception();

        std::cout << "Movie succesfully deleted\n";
        std::cout << "Do you want to add a like to the movie?y/n\n";
        std::string option;
        std::cout << "option: ";
        std::cin >> option;

        if (option == "y")
        {
            Movie movieToBeUpdated = this->service.getMovie(movieTitle);
            int nrOfLikes = movieToBeUpdated.getNumberOfLikes();
            nrOfLikes++;
            movieToBeUpdated.setnumberOfLikes(nrOfLikes);
            this->service.updateMovie(movieToBeUpdated);
            std::cout << "Like succesfully added\n";
        }
        else
        {
            std::cout << "Like not added\n";
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Movie not found in watch list!!!\n";
    }
}
void Ui::printMovies(DynamicVector<Movie> listOfMovies)
{
    for (int i = 0; i < listOfMovies.getSize(); ++i)
    {
        std::cout << "________________________________________________________\n";
        std::cout << "Movie number: " << i + 1 << "\n\n";
        std::cout << "Title: " << listOfMovies[i].getTitle() << "\n";
        std::cout << "Genre :" << listOfMovies[i].getGenre() << "\n";
        std::cout << "Trailer: " << listOfMovies[i].getTrailer() << "\n";
        std::cout << "Year of release: " << listOfMovies[i].getYearOfRelease() << "\n";
        std::cout << "Number of likes: " << listOfMovies[i].getNumberOfLikes() << "\n";
    }

    std::cout << "________________________________________________________\n\n";
}
void Ui::adminAddmovie()
{
    std::string title, genre, trailer;
    int yearOfRelease, numberOfLikes;

    std::cout << "Title: ";
    std::cin.get();
    getline(std::cin, title);
    std::cout << "Genre: ";
    std::cin >> genre;
    std::cout << "Trailer: ";
    std::cin >> trailer;
    std::cout << "Year of release: ";
    std::cin >> yearOfRelease;
    std::cout << "Number of likes: ";
    std::cin >> numberOfLikes;

    Movie movieToBeAdded = Movie(title, genre, trailer, yearOfRelease, numberOfLikes);

    try
    {
        if (this->service.addMovie(movieToBeAdded) == false)
            throw(std::exception());
    }
    catch (const std::exception &e)
    {
        std::cout << "\nMovie already exists!!!\n";
    }
}
void Ui::adminDeleteMovie()
{
    std::string title;

    std::cout << "Title: ";
    std::cin.get();
    getline(std::cin, title);

    try
    {
        if (this->service.deleteMovie(title) == false)
            throw std::exception();
    }
    catch (const std::exception &e)
    {
        std::cout << "\nNo movie found for delete!!!\n";
    }
}
void Ui::adminUpdateMovie()
{
    std::string title, genre, trailer;
    int yearOfRelease, numberOfLikes;

    std::cout << "Title: ";
    std::cin.get();
    getline(std::cin, title);
    std::cout << "New genre: ";
    std::cin >> genre;
    std::cout << "New trailer: ";
    std::cin >> trailer;
    std::cout << "New year of release: ";
    std::cin >> yearOfRelease;
    std::cout << "New number of likes: ";
    std::cin >> numberOfLikes;

    Movie movieToBeUpdated = Movie(title, genre, trailer, yearOfRelease, numberOfLikes);

    try
    {
        if (!this->service.updateMovie(movieToBeUpdated))
            throw std::exception();
    }
    catch (const std::exception &e)
    {
        std::cout << "\nNo movie found for update!!!\n";
    }
}
void Ui::runAdmin()
{
    printAdminMenu();

    while (true)
    {
        std::string option;
        std::cout << "Option :";
        std::cin >> option;

        if (option == addMovie)
            this->adminAddmovie();
        else if (option == updateMovie)
            this->adminUpdateMovie();
        else if (option == deleteMovie)
            this->adminDeleteMovie();
        else if (option == displayAllMovies)
            this->printMovies(this->service.getMovies());
        else if (option == Exit)
            return;
        else
            std::cout << "Invalid option!!\n";
    }
}

void Ui::runUser()
{
    while (true)
    {
        printUserMenu();

        std::string option;
        std::cout << "Option :";
        std::cin >> option;

        if (option == Exit)
            return;
        if (option == printMoviesByGenre)
            this->printMoviesByASpecificGenre();
        else if (option == displayAllMovies)
            this->printMovies(this->service.getMovies());
        else if (option == deleteMovieFromWatchList)
            this->deleteMovieFromWatchListUi();
        else if (option == seeWatchList)
            this->printMovies(this->service.getWatchList());
    }
}
void Ui::printMoviesByASpecificGenre()
{
    std::string genre;
    std::cout << "Enter genre: ";
    std::cin.ignore();
    std::getline(std::cin, genre);

    DynamicVector<Movie> listOfMovies = this->service.getMoviesByGenre(genre);
    int indexOfMovie = 0;

    if (listOfMovies.getSize() == 0)
        std::cout << "No movies matching\n";
    else
        while (true)
        {
            std::cout << "Current Movie:\n";
            std::cout << "________________________________________________________\n";
            std::cout << "Title: " << listOfMovies[indexOfMovie].getTitle() << "\n";
            std::cout << "Genre :" << listOfMovies[indexOfMovie].getGenre() << "\n";
            std::cout << "Trailer: " << listOfMovies[indexOfMovie].getTrailer() << "\n";
            std::cout << "Year of release: " << listOfMovies[indexOfMovie].getYearOfRelease() << "\n";
            std::cout << "Number of likes: " << listOfMovies[indexOfMovie].getNumberOfLikes() << "\n";
            std::cout << "________________________________________________________\n";
            std::cout << "Choose an option!!\n";
            std::cout << "1. Add to watch list\n";
            std::cout << "2. Next\n";
            std::cout << "0. Exit\n";
            std::string option;

            ShellExecuteA(0, 0, listOfMovies[indexOfMovie].getTrailer().c_str(), 0, 0, SW_SHOW);

            std::cin >> option;

            if (option == like)
            {
                std::cout << "Would you like to add it to the watch list?(y/n)\n";
                std::string yesOrNo;
                std::cin >> yesOrNo;

                if (yesOrNo == "y")
                {
                    if (this->service.checkIfMovieIsInWatchList(listOfMovies[indexOfMovie]) == true)
                    {
                        std::cout << "Movie already in watch list...\n";
                        indexOfMovie = (indexOfMovie + 1) % listOfMovies.getSize();
                    }
                    else
                    {
                        this->service.addMovieToWatchList(listOfMovies[indexOfMovie]);
                        std::cout << "Movie succesfully added to watch list!!\n";
                        indexOfMovie = (indexOfMovie + 1) % listOfMovies.getSize();
                    }
                }
                else if (yesOrNo == "n")
                {
                    indexOfMovie = (indexOfMovie + 1) % listOfMovies.getSize();
                    std::cout << "Movie not added!!\n";
                }
                else
                    std::cout << "Invalid option!!\n";
            }
            else if (option == next)
                indexOfMovie = (indexOfMovie + 1) % listOfMovies.getSize();
            else if (option == Exit)
                break;
        }
}
void Ui::startUi()
{
    this->service.generateEntries(10);

    while (true)
    {

        printInitialMenu();

        std::string option;
        std::cout << "Option :";
        std::cin >> option;

        if (option == adminMode)
            runAdmin();
        else if (option == userMode)
            runUser();
        else if (option == Exit)
            return;
        else
            std::cout << "Invalid option!!!!\n";
    }
}