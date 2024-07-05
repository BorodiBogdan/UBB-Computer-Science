#include "repository.h"

class Service
{
private:
    Repository proteinRepo;

public:
    vector<Protein> getAllProteins();
    vector<Protein> getProteinsHavingASpecificNameSortedByOrganism(string name);
    int getNumberOfOrganismsHavingAName(string name);
};