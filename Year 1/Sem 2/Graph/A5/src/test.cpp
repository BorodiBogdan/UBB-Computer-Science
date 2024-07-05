#include <cassert>
#include "../includes/test.h"
#include <iostream>

void testMinimumColouring(){
    Service s;

    for(int i = 0; i < 5; ++i)
        s.addVertex(i);

    s.addEdge(0, 1);
    s.addEdge(1, 2);
    s.addEdge(2, 3);
    s.addEdge(3, 1);

    assert(s.getMinimumColoringGraph().size() == 5);

    int numberOfColors = -1;

    for(auto c : s.getMinimumColoringGraph()) {
        cout << c <<" ";
        if (c > numberOfColors)
            numberOfColors = c;
    }

    assert(numberOfColors == 2);
}