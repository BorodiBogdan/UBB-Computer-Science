#include "domain.h"
#include <vector>
#include <algorithm>

class Repository
{
private:
    vector<Protein> proteinList;

public:
    void addProtein(Protein proteinToBeAdded);
    vector<Protein> getProteins();
};