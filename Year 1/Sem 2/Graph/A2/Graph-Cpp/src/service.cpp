#include "../includes/service.h"
#include <stack>
#include <iostream>
#include <algorithm>
#define Nmax 1000000
#include <queue>

typedef std::map<std::pair<std::string, std::string>, std::vector<std::pair<std::string, std::string>>> CGMWGraph;
Graph Service::getGraph()
{
    return this->myGraph;
}
void Service::destroyGraph()
{
    this->myGraph.destroyGraph();
}
int Service::getNumberOfVertices()
{
    return this->myGraph.getNumberOfVertices();
}
int Service::getNumberOfEdges()
{
    return this->myGraph.getNumberOfEdges();
}
bool Service::isEdge(int vertex1, int vertex2)
{
    return this->myGraph.isEdge(vertex1, vertex2);
}
int Service::getOutDegree(int vertex)
{
    return this->myGraph.getOutDegree(vertex);
}
int Service::getInDegree(int vertex)
{
    return this->myGraph.getInDegree(vertex);
}
void Service::addVertex(int vertex)
{
    // vertex already added
    this->myGraph.addVertex(vertex);
}
void Service::addEdge(int vertex1, int vertex2)
{
    this->myGraph.addEdge(vertex1, vertex2);
}
void Service::removeVertex(int vertex)
{
    this->myGraph.removeVertex(vertex);
}
void Service::removeEdge(int vertex1, int vertex2)
{
    this->myGraph.removeEdge(vertex1, vertex2);
}
int Service::retrieveEdgeInformation(int vertex1, int vertex2)
{
    return this->myGraph.retrieveEdgeInformation(vertex1, vertex2);
}
void Service::modifyEdgeInformation(int vertex1, int vertex2, int information)
{
    this->myGraph.modifyEdgeInformation(vertex1, vertex2, information);
}

//--------------------------- A2 - problems -------------------------------------
void dfsForConnectedComponents(Graph myGraph, std::map<int, int> &visited, int vertex, int &nrOfComponent)
{
    visited[vertex] = nrOfComponent;

    for (auto it = myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
    {
        int newVertex = it->second;

        if (!visited[newVertex])
            dfsForConnectedComponents(myGraph, visited, newVertex, nrOfComponent);
    }
}
std::vector<std::vector<int>> Service::connectedComponents()
{
    std::vector<std::vector<int>> connectedCompList;
    std::map<int, int> visited;
    int nrOfComponent = 0;

    for (auto it = this->myGraph.getVerticeIterator(); it != this->myGraph.getEndOfIteration(); ++it)
    {
        int vertex = it->first;
        if (visited[vertex] == 0)
        {
            nrOfComponent++;
            dfsForConnectedComponents(this->myGraph, visited, vertex, nrOfComponent);
        }
    }
    connectedCompList.resize(nrOfComponent);

    for (auto iterator : visited)
    {
        int vertex = iterator.first;
        int component = iterator.second;
        connectedCompList[component - 1].push_back(vertex);
    }

    return connectedCompList;
}
void inverseTopSort(Graph myGraph, std::map<int, bool> &visited, int vertex, std::stack<int> &result)
{
    visited[vertex] = 1;

    for (auto it = myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
    {
        int newVertex = it->second;

        inverseTopSort(newVertex, visited, newVertex, result);
    }
    result.push(vertex);
}
void DFST(Graph myGraph, std::map<int, bool> &visited, std::vector<std::vector<int>> &stronglyConnectedComponents, int vertex, int cnt)
{
    stronglyConnectedComponents[cnt].push_back(vertex);
    visited[vertex] = true;

    for (auto it = myGraph.getIteratorInboundEdges(vertex); it != myGraph.getEndOfIterationInboundEdges(vertex); ++it)
    {
        int newVertex = it->first;

        if (!visited[newVertex])
            DFST(myGraph, visited, stronglyConnectedComponents, newVertex, cnt);
    }
}
std::vector<std::vector<int>> Service::getStronglyConnectedComponents()
{
    std::stack<int> vertices;
    std::map<int, bool> visited;

    for (auto it = this->myGraph.getVerticeIterator(); it != this->myGraph.getEndOfIteration(); ++it)
    {
        int vertex = it->first;
        if (!visited[vertex])
            inverseTopSort(this->myGraph, visited, vertex, vertices);
    }
    visited.clear();

    std::vector<std::vector<int>> stronglyConnectedComponents;
    int cnt = 0;

    while (vertices.size())
    {
        int vertex = vertices.top();
        vertices.pop();

        if (visited[vertex] == 0)
        {
            stronglyConnectedComponents.resize(cnt + 1);
            DFST(this->myGraph, visited, stronglyConnectedComponents, vertex, cnt++);
        }
    }

    return stronglyConnectedComponents;
}
void generateGraphWGCM(CGMWGraph &WMGCGraph, std::pair<std::string, std::string> state, std::map<std::pair<std::string, std::string>, bool> visited)
{
    std::string start = state.first;
    std::string end = state.second;

    std::string incompabilities[] = {"cgw",
                                     "gw",
                                     "cg"};

    std::string startCopy = start;
    visited[state] = true;

    if (start.find("m") == std::string::npos)
        swap(start, end);

    for (int i = 0; i < start.size(); ++i)
    {

        std::string newEnd = end + "m";

        if (start[i] != 'm')
            newEnd += start[i];

        std::string newStart = "";

        for (auto x : start)
        {
            if (x != 'm' && x != start[i])
                newStart += x;
        }

        bool ok = 1;

        for (auto inc : incompabilities)
            if (inc == newEnd || inc == newStart)
                ok = 0;

        if (ok)
        {
            if (start != startCopy)
                swap(newStart, newEnd);

            sort(newEnd.begin(), newEnd.end());
            sort(newStart.begin(), newStart.end());

            std::pair<std::string, std::string> newState = std::make_pair(newStart, newEnd);
            if (visited[newState] == false)
            {
                WMGCGraph[state].push_back(newState);
                WMGCGraph[newState].push_back(state);
                generateGraphWGCM(WMGCGraph, newState, visited);
            }
        }
    }
}
void reconstructRoad(CGMWGraph t, std::map<std::pair<std::string, std::string>, int> D, std::pair<std::string, std::string> state, std::vector<std::pair<std::string, std::string>> &res)
{
    std::pair<std::string, std::string> firstState = std::make_pair("cgmw", "");
    if (firstState == state)
    {
        res.push_back(state);
        return;
    }
    for (auto newState : t[state])
    {
        if (D[newState] == D[state] - 1)
        {
            reconstructRoad(t, D, newState, res);
            res.push_back(state);

            break;
        }
    }
}
std::vector<std::pair<std::string, std::string>> Service::solveGoatWolfCabbage()
{
    CGMWGraph WMGCGraph;
    std::map<std::pair<std::string, std::string>, bool> visited;
    std::pair<std::string, std::string> firstState = std::make_pair("cgmw", "");
    generateGraphWGCM(WMGCGraph, firstState, visited);

    std::queue<std::pair<std::string, std::string>> Q;
    Q.push(firstState);

    std::map<std::pair<std::string, std::string>, int> D;
    D[firstState] = 1;

    while (!Q.empty())
    {
        std::pair<std::string, std::string> currentState = Q.front();

        for (auto vertex : WMGCGraph[currentState])
        {
            if (D[vertex] == 0)
            {
                D[vertex] = D[currentState] + 1;
                Q.push(vertex);
            }
        }
        Q.pop();
    }

    std::vector<std::pair<std::string, std::string>> res;

    reconstructRoad(WMGCGraph, D, std::make_pair("", "cgmw"), res);
    return res;
}
//--------------------------- A3 - problems -------------------------------------