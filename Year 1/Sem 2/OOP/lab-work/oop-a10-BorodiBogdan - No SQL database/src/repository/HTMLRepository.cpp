#include "../../includes/repository/HTMLRepository.h"

HTMLMovieRepository::HTMLMovieRepository()
{
    this->HTMLFilePath = "";
    this->saveMoviesFromRepository();
}
HTMLMovieRepository::HTMLMovieRepository(string HTMLFilePath)
{
    this->HTMLFilePath = HTMLFilePath;
    this->saveMoviesFromRepository();
}
void HTMLMovieRepository::saveMoviesFromRepository()
{
    ofstream HTMLOutputFile(this->HTMLFilePath);

    if (!HTMLOutputFile.is_open())
        throw FileException("The HTML file could not be opened!");

    HTMLOutputFile << "<!DOCTYPE html> <html> <head> <title> Movie WatchList</title> </head > <body> <table border=\"1\">";
    HTMLOutputFile << "<tr> <td> Index </td> <td> Title </td> <td> Genre </td> <td> Year Of Release </td> <td> Likes Count </td> <td> Trailer </td> </tr>";
    int index = 0;

    for (auto movie : this->listOfMovies)
        HTMLOutputFile << "<tr> <td>" << index++ << "</td> <td>" << movie.getTitle() << "</td> <td>" << movie.getGenre() << "</td> <td>" << movie.getYearOfRelease() << "</td> <td>" << movie.getNumberOfLikes() << "</td> <td><a href=\"" << movie.getTrailer() << "\"> Link</a></ td> </tr>";

    HTMLOutputFile << "</table> </body> </html>";

    HTMLOutputFile.close();
}
void HTMLMovieRepository::loadMoviesInRepository()
{
}
string HTMLMovieRepository::getFileName()
{
    return this->HTMLFilePath;
}