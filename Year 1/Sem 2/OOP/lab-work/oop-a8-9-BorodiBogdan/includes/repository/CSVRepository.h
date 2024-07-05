#pragma once
#include "repository.h"

class CSVRepository : public Repository
{
private:
    string CSVFilePath;

public:
    CSVRepository();
    CSVRepository(string CSVFilePath);
    void saveMoviesFromRepository();
    void loadMoviesInRepository();
    string getFileName();
};