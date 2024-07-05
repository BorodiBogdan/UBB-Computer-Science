#include <iostream>
using namespace std;

class baseClass
{
public:
    virtual const void test()
    {
        cout << "test2";
    }
};

class derivedClass : public baseClass
{
public:
    const void test() override
    {
        cout << "test derived\n";
    }
};

int main()
{
    baseClass b;
    derivedClass d;

    b.test();
    d.test();
}