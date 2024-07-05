#include "repository.h"

class FileRepository : public Repository
{
private:
    string filePathForMovieList;

public:
    FileRepository(string filePathForMovieList);
    void loadMoviesInRepository();
    void saveMoviesFromRepository();
    string getFileName();
    virtual ~FileRepository() {};
};