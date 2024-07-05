#include "test.h"

void Test::testAdd()
{
    Service controller;

    School a = School("Avram_Iancu", 23.60, 46.77, "15.04.2022");
    School b = School("George_Cosbuc", 23.58, 46.77, "15.04.2022");
    School c = School("Alexandru_Vaida", 23.63, 46.77, "15.04.2022");
    School d = School("Romulus_Guga", 24.57, 46.53, "15.04.2022");
    School e = School("Colgeiul_Transilvania", 24.57, 46.54, "15.04.2022");

    controller.addNewSchool(a);
    controller.addNewSchool(b);
    controller.addNewSchool(c);
    controller.addNewSchool(d);
    controller.addNewSchool(e);

    assert(controller.getSchools().size() == 5);

    try
    {
        controller.addNewSchool(a);
        assert(false);
    }
    catch (const char *e)
    {
        assert(true);
    }
}
void Test::testClosestNSchools()
{
    Service controller;
    School a = School("Avram_Ianc12312u", 23.60, 46.77, "15.04.2022");
    School b = School("George_Cosb124uc", 23.58, 46.77, "15.04.2022");

    controller.addNewSchool(a);
    controller.addNewSchool(b);

    vector<School> testVector = controller.getSchoolsSortedByEuclideanSpaceAndName(12.55, 12.44);
    assert(testVector.size() == 2);

    controller.addEntries();

    testVector = controller.getSchoolsSortedByEuclideanSpaceAndName(12.55, 12.44);

    assert(testVector.size() == 3);

    for (int i = 1; i <= 2; ++i)
        assert(testVector[i].getSchoolName() > testVector[i - 1].getSchoolName());
}

void Test::testAll()
{
    std::cout << "Test1....\n";
    testAdd();
    std::cout << "Test2....\n";
    testClosestNSchools();
}