#include "SortedBag.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

bool cmp(TComp a, TComp b){
    return a <= b;
}

int main() {
	testAll();
	testAllExtended();

	system("pause");
}
