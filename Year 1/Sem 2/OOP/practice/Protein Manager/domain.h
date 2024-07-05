using namespace std;
#include <string>

class Protein
{
private:
    string organism, name, sequence;

public:
    string getOrganism();
    string getName();
    string getSequence();
};