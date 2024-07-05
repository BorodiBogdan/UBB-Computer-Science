#include "includes/graph.h"
#include <cassert>
#include <iostream>

Graph createRandomGraph(int vertices, int edges)
{
    Graph randomGraph = Graph(vertices);

    int i = edges;

    while (i > 0)
    {
        int vertex1 = rand() % vertices;
        int vertex2 = rand() % vertices;

        if (!randomGraph.isEdge(vertex1, vertex2) && vertex1 != vertex2)
        {
            randomGraph.addEdge(vertex1, vertex2);
            i--;
        }
    }

    return randomGraph;
}

class TestGraph
{
private:
    void testRandomGraph()
    {
        Graph myRandomGraph = createRandomGraph(200, 50);

        assert(myRandomGraph.getNumberOfEdges() == 50);
        assert(myRandomGraph.getNumberOfVertices() == 200);

        for (int i = 200; i < 500; ++i)
            myRandomGraph.addVertex(i);

        for (int i = 200; i < 500; ++i)
            myRandomGraph.addEdge(i, i - 1);

        assert(myRandomGraph.getNumberOfEdges() == 350);
        assert(myRandomGraph.getNumberOfVertices() == 500);
    }
    void testCloneGraph()
    {
        Graph myRandomGraph = createRandomGraph(200, 50);
        Graph clonedGraph = myRandomGraph; // here we have the clone

        for (int i = 200; i < 500; ++i)
        {
            clonedGraph.addVertex(i);
            assert(clonedGraph.getNumberOfVertices() == i + 1);
            assert(myRandomGraph.getNumberOfVertices() == 200);
        }

        for (int i = 200; i < 500; ++i)
        {
            clonedGraph.addEdge(i, i - 1);
            assert(myRandomGraph.isEdge(i, i - 1) == false);
        }

        assert(clonedGraph.getNumberOfEdges() != myRandomGraph.getNumberOfEdges());
        assert(clonedGraph.getNumberOfVertices() != myRandomGraph.getNumberOfEdges());
    }

public:
    void testAll()
    {
        std::cout << "Test 1...\n";
        testRandomGraph();
        std::cout << "Test 2...\n";
        testCloneGraph();
    }
};

int main()
{
    TestGraph tester;

    std::cout << "Testing....\n";
    tester.testAll();
    std::cout << "All tests passed...\n";
}