#include "service.h"
#include <algorithm>

bool cmp(Protein a, Protein b)
{
    return a.getOrganism() < b.getOrganism();
}

vector<Protein> Service::getAllProteins()
{
    return this->proteinRepo.getProteins();
}

vector<Protein> Service::getProteinsHavingASpecificNameSortedByOrganism(string name)
{
    vector<Protein> result;

    for (auto x : this->proteinRepo.getProteins())
        if (x.getName() == name)
            result.push_back(x);

    sort(result.begin(), result.end(), cmp);

    return result;
}

int Service::getNumberOfOrganismsHavingAName(string name)
{
    int cnt = 0;

    for (auto x : this->proteinRepo.getProteins())
        if (x.getName() == name)
            cnt++;

    return cnt;
}
