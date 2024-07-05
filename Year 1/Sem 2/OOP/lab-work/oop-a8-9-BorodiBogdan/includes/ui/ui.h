#pragma once
#include "../../includes/service/service.h"

class Ui
{
private:
    Service service;

    void printInitialMenu();
    void printAdminMenu();
    void printUserMenu();
    void printMovies(vector<Movie> listOfMovies);
    void adminAddmovie();
    void adminDeleteMovie();
    void adminUpdateMovie();
    void runAdmin();
    void runUser();
    void printMoviesByASpecificGenre();
    void deleteMovieFromWatchListUi();

public:
    Ui();
    void startUi();
};