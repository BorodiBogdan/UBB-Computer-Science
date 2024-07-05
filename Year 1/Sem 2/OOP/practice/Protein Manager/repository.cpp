#include "repository.h"

void Repository::addProtein(Protein proteinToBeAdded)
{
    for (auto x : this->proteinList)
        if (x.getName() == proteinToBeAdded.getName())
            throw("Invalid name!!");

    this->proteinList.push_back(proteinToBeAdded);
}

vector<Protein> Repository::getProteins()
{
    return this->proteinList;
}
