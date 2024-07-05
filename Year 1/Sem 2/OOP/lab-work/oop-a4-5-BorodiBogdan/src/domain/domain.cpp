#include "../../includes/domain/domain.h"

Movie::Movie() : title{""}, genre{""}, trailer{""}, yearOfRelease{0}, numberOfLikes{0} {};
Movie::Movie(std::string &title, std::string &genre, std::string &trailer, int &yearOfRelease, int &numberOfLikes) : title{title}, genre{genre}, trailer{trailer}, yearOfRelease{yearOfRelease}, numberOfLikes{numberOfLikes} {};

std::string Movie::getTitle() const
{
    return this->title;
}

std::string Movie::getGenre() const
{
    return this->genre;
}

std::string Movie::getTrailer() const
{
    return this->trailer;
}

int Movie::getYearOfRelease() const
{
    return this->yearOfRelease;
}

int Movie::getNumberOfLikes() const
{
    return this->numberOfLikes;
}

void Movie::setTitle(std::string &title)
{
    this->title = title;
}

void Movie::setGenre(std::string &genre)
{
    this->genre = genre;
}

void Movie::setTrailer(std::string &trailer)
{
    this->trailer = trailer;
}

void Movie::setYearOfRelease(int &yearOfRelease)
{
    this->yearOfRelease = yearOfRelease;
}

void Movie::setnumberOfLikes(int &numberOfLikes)
{
    this->numberOfLikes = numberOfLikes;
}

Movie &Movie::operator=(const Movie &movie)
{
    if (this == &movie)
        return *this;
    this->title = movie.title;
    this->genre = movie.genre;
    this->trailer = movie.trailer;
    this->yearOfRelease = movie.yearOfRelease;
    this->numberOfLikes = movie.numberOfLikes;

    return *this;
}
