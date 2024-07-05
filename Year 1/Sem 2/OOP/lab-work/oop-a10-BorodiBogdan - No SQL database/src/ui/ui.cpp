#include "../../includes/ui/ui.h"
#include "../../tests/test.h"
#include <iostream>
#include <cassert>

const std::string adminMode = "1";
const std::string userMode = "2";
const std::string Exit = "0";
const std::string addMovie = "1";
const std::string updateMovie = "2";
const std::string deleteMovie = "3";
const std::string displayAllMovies = "4";
const std::string printMoviesByGenre = "1";
const std::string like = "1";
const std::string Next = "2";
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
    displayedString += "2. Update movie\n";
    displayedString += "3. Remove movie\n";
    displayedString += "4. Display movies\n";
    displayedString += "5. Undo\n";
    displayedString += "6. Redo\n";
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

        this->service.deleteMovieFromWatchList(movieTitle);

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
void Ui::printMovies(vector<Movie> listOfMovies)
{
    for (auto movie : listOfMovies)
    {
        std::cout << "________________________________________________________\n";
        std::cout << "Title: " << movie.getTitle() << "\n";
        std::cout << "Genre :" << movie.getGenre() << "\n";
        std::cout << "Trailer: " << movie.getTrailer() << "\n";
        std::cout << "Year of release: " << movie.getYearOfRelease() << "\n";
        std::cout << "Number of likes: " << movie.getNumberOfLikes() << "\n";
    }
    std::cout << "________________________________________________________\n";
}
void Ui::adminAddmovie()
{
    Movie movieToBeAdded;
    std::cout << "Please enter the details of the movie you want to add! Be careful, the format is important!\nThe format is: title | genre | trailer | year of release  | likesCount\n";
    std::cin.ignore();

    try
    {
        cin >> movieToBeAdded;
    }
    catch (MovieExceptions &e)
    {
        for (auto argument : e.returnErrors())
            cout << argument.what() << "\n";

        return;
    }

    try
    {
        this->service.addMovie(movieToBeAdded);
    }
    catch (DuplicateMovieException &e)
    {
        std::cout << e.what() << "\n";
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
        service.deleteMovie(title);
    }
    catch (RepositoryException &e)
    {
        std::cout << e.what() << "\n";
    }
}
void Ui::adminUpdateMovie()
{
    Movie movieToBeUpdated;

    std::cout << "Please enter the details of the movie you want to delete! Be careful, the format is important!\nThe format is: title |  genre | trailer | year of release | likesCount\n";
    std::cin.ignore();
    try
    {
        cin >> movieToBeUpdated;
    }
    catch (MovieExceptions &e)
    {
        for (auto argument : e.returnErrors())
            cout << argument.what() << "\n";

        return;
    }
    try
    {
        this->service.updateMovie(movieToBeUpdated);
    }
    catch (RepositoryException &e)
    {
        cout << e.what() << "\n";
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
        else if(option == "5") {
            try {
                service.executeUndo();
            }
            catch (UndoRedoException &e) {
                cout << e.what() << "\n";
            }
        }
        else if(option == "6"){
            try {
                service.executeRedo();
            }
            catch (UndoRedoException &e){
                cout << e.what() << "\n";
            }
        }
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
        {
            this->printMovies(this->service.getWatchList());
            this->service.openWatchList();
        }
    }
}
void Ui::printMoviesByASpecificGenre()
{
    std::string genre;
    std::cout << "Enter genre: ";
    std::cin.ignore();
    std::getline(std::cin, genre);

    vector<Movie> listOfMovies = this->service.getMoviesByGenre(genre);
    int indexOfMovie = 0;

    if (listOfMovies.size() == 0)
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

            //ShellExecuteA(0, 0, listOfMovies[indexOfMovie].getTrailer().c_str(), 0, 0, SW_SHOW);

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
                        indexOfMovie = (indexOfMovie + 1) % listOfMovies.size();
                    }
                    else
                    {
                        this->service.addMovieToWatchList(listOfMovies[indexOfMovie]);
                        std::cout << "Movie succesfully added to watch list!!\n";
                        indexOfMovie = (indexOfMovie + 1) % listOfMovies.size();
                    }
                }
                else if (yesOrNo == "n")
                {
                    indexOfMovie = (indexOfMovie + 1) % listOfMovies.size();
                    std::cout << "Movie not added!!\n";
                }
                else
                    std::cout << "Invalid option!!\n";
            }
            else if (option == Next)
                indexOfMovie = (indexOfMovie + 1) % listOfMovies.size();
            else if (option == Exit)
                break;
        }
}
void Ui::startUi()
{
    // this->service.generateEntries(10);
    while (true)
    {
        cout << "0. Exit\n1 - Real database\n2 - TXT file\n";

        int option;
        cout << "Option: ";
        cin >> option;

        if (option == 0)
            break;
        else
            this->service.setTypeOfDataBase(option);

        while (true)
        {
            cout << "0. Exit\nCSV - CSV file\nHTML - HTML file\nOther - txt file\n";
            string fileType;

            cout << "File type: ";
            cin >> fileType;

            if (fileType == "0")
                break;

            this->service.setTypeOfRepo(fileType);

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
                    break;
                else
                    std::cout << "Invalid option!!!!\n";
            }
        }
    }
}