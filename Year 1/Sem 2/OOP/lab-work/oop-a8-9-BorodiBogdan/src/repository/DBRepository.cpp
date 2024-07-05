#include "../../includes/repository/repository.h"
#include "../../includes/exceptions/Exceptions.h"
#include <fstream>
#include <sqlite3.h>
#include "../../includes/repository/DBRepository.h"

DBRepository::DBRepository(std::string dataBaseName)
{
    this->dataBaseName = dataBaseName;
    int errorCode = sqlite3_open(this->dataBaseName.c_str(), &this->databaseWithMovies);

    if (errorCode != SQLITE_OK)
        throw RepositoryException("Could not open database");

    std::string createTableStatement = "CREATE TABLE IF NOT EXISTS Movies (Title TEXT PRIMARY KEY, Genre TEXT, Trailer TEXT, YearOfRelease INTEGER, LikesCount INTEGER);";
    char *errorMessage;
    errorCode = sqlite3_exec(this->databaseWithMovies, createTableStatement.c_str(), NULL, 0, &errorMessage);
    free(errorMessage);
    if (errorCode != SQLITE_OK)
        throw RepositoryException("Could not create table");

    this->loadMoviesInRepository();
}

DBRepository::~DBRepository()
{
    sqlite3_close(this->databaseWithMovies);
}

void DBRepository::addMovie(Movie movieToBeAdded)
{

    Repository::addMovie(movieToBeAdded);

    std::string insertStatement = "INSERT INTO Movies VALUES ('" + movieToBeAdded.getTitle() + "', '" + movieToBeAdded.getGenre() + "', '" + movieToBeAdded.getTrailer() + "', " + std::to_string(movieToBeAdded.getYearOfRelease()) + ", " + std::to_string(movieToBeAdded.getNumberOfLikes()) + ");";
    char *errorMessage;
    int errorCode = sqlite3_exec(this->databaseWithMovies, insertStatement.c_str(), NULL, 0, &errorMessage);
    free(errorMessage);
    if (errorCode != SQLITE_OK)
        throw RepositoryException("Could not add movie");
}

void DBRepository::deleteMovie(std::string &movieToBeRemoved)
{
    // Using a parameterized SQL statement to prevent SQL injection
    std::string deleteStatement = "DELETE FROM Movies WHERE Title = ?";

    // Prepare the SQL statement
    sqlite3_stmt *stmt;
    int errorCode = sqlite3_prepare_v2(this->databaseWithMovies, deleteStatement.c_str(), -1, &stmt, NULL);
    if (errorCode != SQLITE_OK)
    {
        throw RepositoryException("Failed to prepare statement");
    }

    // Bind the title to the SQL query
    sqlite3_bind_text(stmt, 1, movieToBeRemoved.c_str(), -1, SQLITE_STATIC);

    // Execute the prepared statement
    errorCode = sqlite3_step(stmt);
    if (errorCode != SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw RepositoryException("Could not remove movie");
    }

    // Clean up
    sqlite3_finalize(stmt);

    // Call the higher-level delete movie method if needed
    Repository::deleteMovie(movieToBeRemoved);
}

void DBRepository::updateMovie(Movie updatedMovie)
{
    // Using a parameterized SQL statement to prevent SQL injection
    std::string updateStatement = "UPDATE Movies SET Title = ?, Genre = ?, Trailer = ?, YearOfRelease = ?, LikesCount = ? WHERE Title = ?";

    // Prepare SQL statement (assuming sqlite3_prepare_v2 is available)
    sqlite3_stmt *stmt;
    int errorCode = sqlite3_prepare_v2(this->databaseWithMovies, updateStatement.c_str(), -1, &stmt, NULL);

    if (errorCode != SQLITE_OK)
    {
        throw RepositoryException("Failed to prepare statement");
    }

    // Bind parameters (assuming sqlite3_bind_text and sqlite3_bind_int are correct methods)
    sqlite3_bind_text(stmt, 1, updatedMovie.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, updatedMovie.getGenre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, updatedMovie.getTrailer().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, updatedMovie.getYearOfRelease());
    sqlite3_bind_int(stmt, 5, updatedMovie.getNumberOfLikes());
    sqlite3_bind_text(stmt, 6, updatedMovie.getTitle().c_str(), -1, SQLITE_STATIC);

    // Execute the prepared statement
    errorCode = sqlite3_step(stmt);
    // Clean up
    sqlite3_finalize(stmt);
}

void DBRepository::saveMoviesFromRepository()
{
}

void DBRepository::loadMoviesInRepository()
{
    std::string selectStatement = "SELECT * FROM Movies;";
    sqlite3_stmt *statement;
    int errorCode = sqlite3_prepare_v2(this->databaseWithMovies, selectStatement.c_str(), -1, &statement, NULL);

    if (errorCode != SQLITE_OK)
    {
        free(statement);
        throw RepositoryException("Could not load movies into repository");
    }
    while (sqlite3_step(statement) == SQLITE_ROW)
    {
        std::string selectStatement = "SELECT * FROM Movies;";
        sqlite3_stmt *statement;
        int errorCode = sqlite3_prepare_v2(this->databaseWithMovies, selectStatement.c_str(), -1, &statement, NULL);

        if (errorCode != SQLITE_OK)
        {
            free(statement);
            throw RepositoryException("Could not load movies into repository");
        }
        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            std::string title = std::string(reinterpret_cast<const char *>(sqlite3_column_text(statement, 0)));
            std::string genre = std::string(reinterpret_cast<const char *>(sqlite3_column_text(statement, 1)));
            int yearOfRelease = sqlite3_column_int(statement, 3);
            int likesCount = sqlite3_column_int(statement, 4);
            std::string trailer = std::string(reinterpret_cast<const char *>(sqlite3_column_text(statement, 2)));

            Movie movie(title, genre, trailer, yearOfRelease, likesCount);
            try
            {
                if(Repository::checkIfMovieIsInRepository(movie) == false)
                    this->listOfMovies.push_back(movie);
            }
            catch (const std::exception &e)
            {
                break;
            }
        }
        sqlite3_finalize(statement);
    }
}
string DBRepository::getFileName()
{
    return this->dataBaseName;
}