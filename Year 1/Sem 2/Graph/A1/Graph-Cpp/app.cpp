#include "includes/ui.h"

// Create a random graph with specified number of vertices and of edges (as an external function).

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

int main()
{
    Ui ui;

    // ui.readGraph("in.txt");
    ui.myGraph = createRandomGraph(100, 50);
    ui.DisplayGraph("out.txt");
    ui.startUi();
}