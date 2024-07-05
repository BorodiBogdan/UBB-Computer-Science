#pragma once
#include <string>
#include <iostream>
#include "../validators/MovieValidator.h"
#include "../utils/Utils.h"
using namespace std;

class Movie
{
private:
    std::string title, genre, trailer;
    int yearOfRelease, numberOfLikes;

public:
    /*
    `Movie` class constructor
    */
    Movie();

    /*
    Movie class constructor
    @param title - the title of the movie
    @param genre - the genre of the movie
    @param trailer - the trailer of the movie
    @param yearOfRelease - the year of release of the movie
    @param numberOfLikes - the number of likes of the movie
    */
    Movie(std::string &title, std::string &genre, std::string &trailer, int yearOfRelease, int numberOfLikes);

    /*
    string getTitle() - returns the title of the movie
    */
    std::string getTitle() const;

    /*
    string getGenre() - returns the genre of the movie
    */
    std::string getGenre() const;

    /*
    string getTrailer() - returns the trailer of the movie
    */
    std::string getTrailer() const;

    /*
    int getYearOfRelease() - returns the year of release of the movie
    */
    int getYearOfRelease() const;

    /*
    int getNumberOfLikes() - returns the number of likes of the movie
    */
    int getNumberOfLikes() const;

    /*
    void setTitle() - sets the title of the movie
    param title - the title of the movie
    */
    void setTitle(std::string &title);

    /*
    void setGenre() - sets the genre of the movie
    param genre - the genre of the movie
    */
    void setGenre(std::string &genre);

    /*
    void setTrailer() - sets the trailer of the movie
    param trailer - the trailer of the movie

    */
    void setTrailer(std::string &trailer);

    /*
    void setYearOfRelease() - sets the year of release of the movie
    param yearOfRelease - the year of release of the movie
    */
    void setYearOfRelease(int &yearOfRelease);

    /*
    void setnumberOfLikes() - sets the number of likes of the movie
    param numberOfLikes - the number of likes of the movie
    */
    void setnumberOfLikes(int &numberOfLikes);

    /*
    Movie &operator=(const Movie &movie) - overloads the = operator
    param movie - the movie to be copied
    */
    Movie &operator=(const Movie &movie);

    bool operator==(const Movie &c);

    friend ostream &operator<<(ostream &output, const Movie &c);
    friend istream &operator>>(istream &input, Movie &c);
};