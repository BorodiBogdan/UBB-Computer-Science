#pragma once
#include <vector>
#include <map>

struct Edge
{
    int first, second;
};

typedef std::map<int, std::vector<Edge>>::iterator mapIterator;
typedef std::vector<Edge>::iterator edgeIterator;

class Graph
{
private:
    int numberOfEdges;
    int numberOfVertices;

    std::map<int, std::vector<Edge>> inEdges;
    std::map<int, std::vector<Edge>> outEdges;
    std::map<std::pair<int, int>, int> edgeInformation;

public:
    // Constructor
    Graph(int n);

    // getNumberOfVertices
    int getNumberOfVertices();
    int getNumberOfEdges();
    // given two vertices, find out whether there is an edge from the first one to the second one
    bool isEdge(int vertex1, int vertex2);

    int getOutDegree(int vertex);

    int getInDegree(int vertex);

    // retrieve or modify the information (the integer) attached to a specified edge.
    void ModifyCost(int sourceVertex, int DestinationVertex, int newCost);

    // add a vertex
    void addVertex(int vertex);

    // remove a vertex
    void removeVertex(int vertex);
    // Destructor

    // verticeIterator
    mapIterator getVerticeIterator();

    // get the end of vertice iteration
    mapIterator getEndOfIteration();
    // destructor

    // iterator for inEdges
    edgeIterator getIteratorInboundEdges(int vertex);

    // end of iteration
    edgeIterator getEndOfIterationInboundEdges(int vertex);

    // iterator for outEdges
    edgeIterator getIteratorOutboundEdges(int vertex);
    edgeIterator getEndOfIterationOutboundEdges(int vertex);
    // add edges
    void addEdge(int vertex1, int vertex2);

    // modifies the cost of an edge
    void modifyEdgeInformation(int vertex1, int vertex2, int information);

    // gives the cost of an edge
    int retrieveEdgeInformation(int vertex1, int vertex2);

    // removes an edge
    void removeEdge(int vertex1, int vertex2);
    void destroyGraph();
};