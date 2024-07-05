#include "ExtendedTest.h"
#include "ShortTest.h"

#include "SortedMap.h"

#include <iostream>
using namespace std;

bool relation1(int a, int b)
{
	return a >= b;
}

int main()
{
	testAll();
	testAllExtended();

	cout << "That's all!" << endl;
	system("pause");
	return 0;
}
