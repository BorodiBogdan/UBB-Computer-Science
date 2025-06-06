#include "graph.h"
#include <string>
using namespace std;

class Service
{
private:
    Graph myGraph = Graph(0);

    void topSortDfs(int vertex, vector<bool> &processed, vector<bool> &fullyProcessed, vector<int> &topSort, bool &isCicle);
    vector<int> topSort();

public:
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

    // returns the conneted components
    std::vector<std::vector<int>> connectedComponents();

    std::vector<std::vector<int>> getStronglyConnectedComponents();
    //
    void destroyGraph();

    Graph getGraph();

    std::vector<std::pair<std::string, std::string>> solveGoatWolfCabbage();

    int solveTorchProblem(int nrOfPeople, std::vector<int> cost);

    int getNumberOfRoads(int sourceVertex, int targetVertex);

    int reverseDijkstra(int sourceVertex, int destinationVertex);

    int getNumberOfMinimumCostRoads(int sourceVertex, int destinationVertex);

    int getMaximumCostPath(int startVertex, int endVertex);

    vector<vector<int>> reconstructTree(std::vector<int> preOrder, std::vector<int> inOrder);

    vector<int> getMinimumColoringGraph();

    vector<int> getMinimumColouringGraphGreedy();
};