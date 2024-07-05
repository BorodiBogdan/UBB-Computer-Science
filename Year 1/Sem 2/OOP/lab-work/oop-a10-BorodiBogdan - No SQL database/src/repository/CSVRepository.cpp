#include "../../includes/repository/CSVRepository.h"

CSVRepository::CSVRepository()
{
    this->CSVFilePath = "";
    this->saveMoviesFromRepository();
}
CSVRepository::CSVRepository(string CSVFilePath)
{
    this->CSVFilePath = CSVFilePath;

    this->saveMoviesFromRepository();
}
void CSVRepository::saveMoviesFromRepository()
{
    std::ofstream CSVOutputFile(this->CSVFilePath);

    if (!CSVOutputFile.is_open())
        throw FileException("The CSV file could not be opened!");

    CSVOutputFile << "Index, Name, Genre, Year Of Release, Trailer, Likes Count\n";
    int index = 0;
    for (auto movie : this->listOfMovies)
        CSVOutputFile << index++ << ", " << movie.getTitle() << "," << movie.getGenre() << "," << movie.getYearOfRelease() << "," << movie.getTrailer() << "," << movie.getNumberOfLikes() << "\n";

    CSVOutputFile.close();
}
void CSVRepository::loadMoviesInRepository()
{
}
string CSVRepository::getFileName()
{
    return this->CSVFilePath;
}