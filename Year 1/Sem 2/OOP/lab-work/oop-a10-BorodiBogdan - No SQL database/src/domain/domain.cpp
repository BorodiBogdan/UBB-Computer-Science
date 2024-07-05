#include "../../includes/domain/domain.h"
#include <cstring>

Movie::Movie() : title{""}, genre{""}, trailer{""}, yearOfRelease{0}, numberOfLikes{0} {};
Movie::Movie(std::string &title, std::string &genre, std::string &trailer, int yearOfRelease, int numberOfLikes) : title{title}, genre{genre}, trailer{trailer}, yearOfRelease{yearOfRelease}, numberOfLikes{numberOfLikes} {};

ostream &operator<<(ostream &output, const Movie &c)
{

    output << c.getTitle() << " | " << c.getGenre() << " | " << c.getTrailer() << " | " << c.getYearOfRelease() << " | " << c.getNumberOfLikes() << "\n";

    return output;
}
istream &operator>>(istream &input, Movie &c)
{
    string line;
    getline(input, line);

    vector<string> parameters;

    string parameter = "";

    for (auto ch : line)
    {
        if (ch == '|')
        {
            Utils::trimWhiteSpaces(parameter);
            parameters.push_back(parameter);
            parameter = "";

        }
        else
            parameter += ch;
    }
    Utils::trimWhiteSpaces(parameter);
    parameters.push_back(parameter);

    if (parameters.size() != 5)
        throw MovieExceptions("Invalid number of parameters!");

    string title = parameters[0];
    string genre = parameters[1];
    string trailer = parameters[2];
    string yearOfRealease = parameters[3];
    string nrOfLikes = parameters[4];

    MovieValidator::validateMovieIdentifiers(title, genre, trailer, yearOfRealease, nrOfLikes);

    c = Movie(title, genre, trailer, stoi(yearOfRealease), stoi(nrOfLikes));

    return input;
}
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

bool Movie::operator==(const Movie &c)
{
    return this->getTitle() == c.getTitle();
}