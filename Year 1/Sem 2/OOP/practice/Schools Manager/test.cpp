#include "test.h"
#include <cassert>
#include <iostream>

void Test::testRemove()
{
    service.addEntries();

    try
    {
        service.deleteSchool("testetstsd");
        assert(false);
    }
    catch (const char *e)
    {
        assert(true);
    }

    vector<School> list = service.getSchoolsListSortedByName();
    for (int i = 4; i >= 0; --i)
    {
        service.deleteSchool(list[i].getName());
        assert(service.getSchoolsListSortedByName().size() == i);
    }
    assert(service.getSchoolsListSortedByName().size() == 0);
}
void Test::testMarkAndRetrieve()
{
    service.addEntries();
    vector<School> list = service.markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited("05.05.1000");
    assert(list.size() == 5);
    list = service.markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited("05.05.2100");
    assert(list.size() == 0);
    list = service.markSchoolsAsVisitedAndRetrieveSchoolsThatAreNotVisited("05.05.1000");
    assert(list.size() == 0);
}

void Test::testAll()
{
    std::cout << "Test1....\n";
    testRemove();
    std::cout << "Test2....\n";
    testMarkAndRetrieve();
    std::cout << "All tests passed\n";
}
