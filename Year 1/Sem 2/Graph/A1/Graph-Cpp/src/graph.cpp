#include "../includes/graph.h"

/*
- get the number of vertices;
- parse (iterate) the set of vertices;
- given two vertices, find out whether there is an edge from the first one to the second one, and retrieve the Edge_id if there is an edge (the latter is not required if an edge is represented simply as a pair of vertex identifiers);
- get the in degree and the out degree of a specified vertex;
- parse (iterate) the set of outbound edges of a specified vertex (that is, provide an iterator). For each outbound edge, the iterator shall provide the Edge_id of the curren edge (or the target vertex, if no Edge_id is used).
- parse the set of inbound edges of a specified vertex (as above);
- get the endpoints of an edge specified by an Edge_id (if applicable);
- retrieve or modify the information (the integer) attached to a specified edge.
- The graph shall be modifiable: it shall be possible to add and remove an edge, and to add and remove a vertex.
- The graph shall be copyable, that is, it should be possible to make an exact copy of a graph, so that the original can be then modified independently of its copy. Think about the desirable behaviour of an Edge_property attached to the original graph, when a copy is made.
- Read the graph from a text file (as an external function); see the format below.
- Write the graph from a text file (as an external function); see the format below.

- Create a random graph with specified number of vertices and of edges (as an external function).
*/

Graph::Graph(int n)
{
    this->numberOfVertices = 0;
    this->numberOfEdges = 0;

    for (int i = 0; i < n; ++i)
        addVertex(i);
}

Graph::~Graph()
{
    for (int i = 0; i < this->numberOfVertices; ++i)
        inEdges[i].clear(),
            outEdges[i].clear();

    inEdges.clear();
    outEdges.clear();

    this->numberOfVertices = 0;
}
int Graph::getNumberOfVertices()
{
    return this->numberOfVertices;
}
int Graph::getNumberOfEdges()
{
    return this->numberOfEdges;
}
bool Graph::isEdge(int vertex1, int vertex2)
{
    auto search = edgeInformation.find({vertex1, vertex2});

    if (search == edgeInformation.end())
        return false;

    return true;
}
int Graph::getOutDegree(int vertex)
{
    return this->outEdges[vertex].size();
}
int Graph::getInDegree(int vertex)
{
    return this->inEdges[vertex].size();
}
void Graph::addVertex(int vertex)
{
    // vertex already added
    if (this->inEdges.find(vertex) != inEdges.end())
        return;

    this->inEdges[vertex].resize(0);
    this->outEdges[vertex].resize(0);
    this->numberOfVertices++;
}
void Graph::addEdge(int vertex1, int vertex2)
{
    this->numberOfEdges++;
    inEdges[vertex2].push_back({vertex1, vertex2});
    outEdges[vertex1].push_back({vertex1, vertex2});
    edgeInformation[{vertex1, vertex2}] = 0;
}
void Graph::removeVertex(int vertex)
{
    for (auto it : inEdges)
    {
        auto vectorOfEdges = it.second;

        std::vector<Edge>::iterator vectorIterator = vectorOfEdges.begin();

        for (; vectorIterator != vectorOfEdges.end(); vectorIterator++)
            if (vectorIterator->first == vertex || vectorIterator->second == vertex)
            {
                vectorOfEdges.erase(vectorIterator);
                std::pair<int, int> currentEdge = {vectorIterator->first, vectorIterator->second};

                if (edgeInformation.find(currentEdge) != edgeInformation.end())
                    edgeInformation.erase(currentEdge);

                vectorIterator--;
            }
    }
    this->numberOfVertices--;
    inEdges.erase(vertex);
    outEdges.erase(vertex);
}
void Graph::removeEdge(int vertex1, int vertex2)
{
    if (!isEdge(vertex1, vertex2))
        return;

    std::vector<Edge> &listOfInEdges = inEdges[vertex2]; // Use reference to avoid unnecessary copy

    auto vectorIterator = listOfInEdges.begin(); // Use begin()
    auto end1 = listOfInEdges.end();             // Use end()

    // Removing {vertex1, vertex2} edges from inboundEdges
    while (vectorIterator != end1)
    {
        Edge currentEdge = {vectorIterator->first, vectorIterator->second};

        if (currentEdge.first == vertex1)
        {
            vectorIterator = listOfInEdges.erase(vectorIterator); // Update iterator after erase
            this->numberOfEdges--;
        }
        else
        {
            ++vectorIterator;
        }
    }
    // removing{vertex1, vertex2} edges from outBoundEdges

    auto end = getEndOfIterationOutboundEdges(vertex1);

    std::vector<Edge> &listOfOutEdges = outEdges[vertex1]; // Use reference to avoid unnecessary copy

    vectorIterator = listOfOutEdges.begin();
    while (vectorIterator != end)
    {
        Edge currentEdge = {vectorIterator->first, vectorIterator->second};

        if (currentEdge.second == vertex2)
        {
            vectorIterator = listOfOutEdges.erase(vectorIterator); // Update iterator after erase
            this->numberOfEdges--;
            // No need to decrement the iterator here
        }
        else
        {
            ++vectorIterator;
        }
        end = getEndOfIterationOutboundEdges(vertex1);
    }
}
int Graph::retrieveEdgeInformation(int vertex1, int vertex2)
{
    if (isEdge(vertex1, vertex2))
        return edgeInformation[{vertex1, vertex2}];
    else
        return -1;
}
mapIterator Graph::getVerticeIterator()
{
    return inEdges.begin();
}

mapIterator Graph::getEndOfIteration()
{
    return inEdges.end();
}
edgeIterator Graph::getIteratorInboundEdges(int vertex)
{
    return inEdges[vertex].begin();
}
edgeIterator Graph::getEndOfIterationInboundEdges(int vertex)
{
    return inEdges[vertex].end();
}
edgeIterator Graph::getIteratorOutboundEdges(int vertex)
{
    return outEdges[vertex].begin();
}
edgeIterator Graph::getEndOfIterationOutboundEdges(int vertex)
{
    return outEdges[vertex].end();
}
void Graph::modifyEdgeInformation(int vertex1, int vertex2, int information)
{
    edgeInformation[{vertex1, vertex2}] = information;
}