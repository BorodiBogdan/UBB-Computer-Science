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
// Torch problem

int min(int a, int b)
{
    return a > b ? b : a;
}
int max(int a, int b)
{
    return a < b ? b : a;
}
/*
Use a lowest cost path algorithm and a new implementation of the interface from lab 1 to solve
the bridge and torch problem: A number of people (up to 20) must cross a bridge, at night.
They have a torch that provides only enough light for at most two people to cross together. For each person,
we are given the time needed to cross the bridge alone. If two people cross together, they cross at the pace
of the slowest one. Find a solution for all to cross the river, using as little time as possible.
*/
int Service::solveTorchProblem(int nrOfPeople, std::vector<int> cost)
{
    int startingVertex = (1 << nrOfPeople) - 1;
    int endingVertex = 0;

    std::queue<std::pair<int, int>> Q;
    std::vector<int> minCost(1 << nrOfPeople, 1 << 26);

    Q.push({startingVertex, 0});
    minCost[startingVertex] = 0;

    while (Q.size())
    {
        int notCrossingPeople = Q.front().first;
        int currentCost = Q.front().second;
        int peopleWhoCrossedTheBridge = notCrossingPeople ^ ((1 << (nrOfPeople + 1)) - 1);
        Q.pop();

        //  no need to generate other entries
        if (currentCost > minCost[notCrossingPeople])
            continue;

        // if we have a 1 bit on the i'th position, then person number i is on that side
        // when we cross the bridge we always cross with two people
        // when we return just one person crosses, and it will be the Fastest person that already crossed the bridge
        // to generate the succeding states we will chose two people to cross, and the fastest one that crossed the bridge
        // will return

        // we will number the bits from right to left

        // there is an edge case, in case we have just two people left, if so we will treat it here

        if (__builtin_popcount(notCrossingPeople) == 2)
        {
            int costToAdd = -1;
            for (int i = 0; i < nrOfPeople; ++i)
            {
                if (notCrossingPeople & 1)
                    costToAdd = max(costToAdd, cost[i]);

                notCrossingPeople >>= 1;
            }

            if (minCost[0] > currentCost + costToAdd)
                minCost[0] = currentCost + costToAdd;

            continue;
        }
        int fastest_one = -1, fastestPace = 1e9;

        for (int i = 0; i < nrOfPeople; ++i)
        {
            if (cost[i] < fastestPace && peopleWhoCrossedTheBridge % 2 == 1)
            {
                fastestPace = cost[i];
                fastest_one = i;
            }
            peopleWhoCrossedTheBridge >>= 1;
        }

        // we know who's the fastest person that already crossed, now let's generate the possible states

        for (int i = 0; i < nrOfPeople; ++i)
            if (notCrossingPeople & (1 << i))
                for (int j = i + 1; j < nrOfPeople; ++j)
                    if (notCrossingPeople & (1 << j))
                    {
                        int passCost = max(cost[i], cost[j]);
                        int whoReturns = j;

                        if (cost[i] < cost[whoReturns])
                            whoReturns = i;

                        if (fastestPace < cost[whoReturns])
                            whoReturns = fastest_one;

                        int crossingCost = passCost + cost[whoReturns];

                        // we know who returns, who remains and the cost
                        // it's time to generate the new configuration
                        // we flip the bits corresponding to the people that first cross to 0
                        // then we flip the bit corresponding to the coming person to 1

                        int going = (1 << i) + (1 << j);
                        int coming = 1 << whoReturns;
                        int newState = (notCrossingPeople ^ going) ^ coming;

                        if (minCost[notCrossingPeople] + crossingCost < minCost[newState])
                        {

                            Q.push({newState, minCost[notCrossingPeople] + crossingCost});
                            minCost[newState] = minCost[notCrossingPeople] + crossingCost;
                        }
                    }
    }

    return minCost[0];
}
void Service::topSortDfs(int vertex, vector<bool> &processed, vector<bool> &fullyProcessed, vector<int> &topSort, bool &isCicle)
{
    processed[vertex] = true;

    for (auto it = myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
    {
        int newVertex = it->second;

        if (processed[newVertex])
        {
            isCicle = 1;
            return;
        }

        if (!fullyProcessed[newVertex])
            this->topSortDfs(newVertex, processed, fullyProcessed, topSort, isCicle);
    }
    processed[vertex] = false;
    topSort.push_back(vertex);
    fullyProcessed[vertex] = true;
}
vector<int> Service::topSort()
{
    vector<int> Nodes;
    vector<bool> proccesed(myGraph.getNumberOfVertices() + 1, false);
    vector<bool> fullyProccesed(myGraph.getNumberOfVertices() + 1, false);
    bool cycle = 0;

    auto iterator = this->myGraph.getVerticeIterator();

    for (; iterator != this->myGraph.getEndOfIteration(); iterator++)
    {
        int vertex = iterator->first;
        if (fullyProccesed[vertex] == 0)
        {
            this->topSortDfs(vertex, proccesed, fullyProccesed, Nodes, cycle);

            if (cycle == 1)
            {
                Nodes.clear();
                return Nodes;
            }
        }
    }

    reverse(Nodes.begin(), Nodes.end());

    return Nodes;
}
int Service::getNumberOfRoads(int sourceVertex, int targetVertex)
{
    if (this->topSort().size() == 0)
        return -1;

    vector<int> dp(myGraph.getNumberOfVertices() + 1, 0);

    dp[sourceVertex] = 1;

    for (auto vertex : this->topSort())
    {
        for (auto it = this->myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
        {

            int newVertex = it->second;
            dp[newVertex] = dp[vertex] + dp[newVertex];
        }
    }

    return dp[targetVertex];
}

int Service::reverseDijkstra(int sourceVertex, int destinationVertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<int> D(myGraph.getNumberOfVertices() + 1, 1 << 28);
    D[destinationVertex] = 0;

    Q.push({0, destinationVertex});

    while (!Q.empty())
    {
        int vertex = Q.top().second;
        int cost = Q.top().first;
        Q.pop();

        for (auto iterator = this->myGraph.getIteratorInboundEdges(vertex); iterator != this->myGraph.getEndOfIterationInboundEdges(vertex); iterator++)
        {
            int newVertex = iterator->first;
            int cost = myGraph.retrieveEdgeInformation(newVertex, vertex);

            if (D[newVertex] > D[vertex] + cost)
            {
                D[newVertex] = D[vertex] + cost;
                Q.push({D[vertex] + cost, newVertex});
            }
        }
    }
    return D[sourceVertex];
}

void getDegree(Graph myGraph, int vertex, vector<int> &Degree)
{
    queue<int> Q;
    Q.push(vertex);

    while (!Q.empty())
    {
        vertex = Q.front();
        Q.pop();

        for (auto it = myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); it++)
        {
            int newVertex = it->second;

            if (Degree[newVertex] == 0)
                Q.push(newVertex);

            Degree[newVertex]++;
        }
    }
}

int Service::getNumberOfMinimumCostRoads(int sourceVertex, int destinationVertex)
{
    if (this->topSort().size() == 0)
        return -1;

    vector<int> Degree(myGraph.getNumberOfVertices());
    vector<int> Cost(myGraph.getNumberOfVertices() + 1, 1 << 28);
    vector<int> Count(myGraph.getNumberOfVertices() + 1, 0);

    getDegree(this->myGraph, sourceVertex, Degree);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    Q.push({0, sourceVertex});
    Cost[sourceVertex] = 0;
    Count[sourceVertex] = 1;

    while (!Q.empty())
    {
        int vertex = Q.top().second;
        int cost = Q.top().first;
        Q.pop();

        for (auto it = myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); it++)
        {
            int newVertex = it->second;
            int edgeCost = myGraph.retrieveEdgeInformation(vertex, newVertex);
            Degree[newVertex]--;

            if (Cost[newVertex] > Cost[vertex] + edgeCost)
            {
                Cost[newVertex] = Cost[vertex] + edgeCost;
                Count[newVertex] = Count[vertex];
            }
            else if (Cost[newVertex] == Cost[vertex] + edgeCost)
                Count[newVertex] += Count[vertex];

            if (Degree[newVertex] == 0)
                Q.push({Cost[newVertex], newVertex});
        }
    }
    return Count[destinationVertex];
}

int Service::getMaximumCostPath(int startVertex, int endVertex)
{
    vector<int> topSortNodes = this->topSort();

    if (topSortNodes.size() == 0)
        return -1;

    vector<int> dp(this->myGraph.getNumberOfVertices() + 1, -1 << 28);

    dp[startVertex] = 0;

    for (auto vertex : topSortNodes)
        for (auto it = this->myGraph.getIteratorOutboundEdges(vertex); it != myGraph.getEndOfIterationOutboundEdges(vertex); ++it)
        {
            int newVertex = it->second;
            int cost = myGraph.retrieveEdgeInformation(vertex, newVertex);

            dp[newVertex] = max(dp[vertex] + cost, dp[newVertex]);
        }

    return dp[endVertex];
}

void reconstruct(const vector<int> &preorder, const vector<int> &inorder, int lpre, int rpre, int lin, int rin, vector<vector<int>> &tree)
{
    // here we need to reconstruct the tree based on preorder and inorder traversal
    // we know that the first element in the preorder traversal is the root of the tree
    // we will find the root in the inorder traversal, and we will split the inorder traversal in two parts

    if (lpre >= rpre || lin >= rin)
        return;

    int root = preorder[lpre];
    int rootIndex = -1;

    for (int i = lin; i < rin; ++i)
        if (inorder[i] == root)
        {
            rootIndex = i;
            break;
        }

    int dim = rootIndex - lin;
    tree[root].push_back(preorder[lpre + 1]);
    tree[root].push_back(preorder[lpre + 1 + dim]);

    reconstruct(preorder, inorder, lpre + 1, lpre + 1 + dim, lin, rootIndex - 1, tree);
    reconstruct(preorder, inorder, lpre + 1 + dim, rpre, rootIndex + 1, rin, tree);
}

vector<vector<int>> Service::reconstructTree(std::vector<int> preOrder, std::vector<int> inOrder)
{
    int size = preOrder.size();

    if (size == 0)
        return {};

    vector<vector<int>> tree(size + 1);

    reconstruct(preOrder, inOrder, 0, size - 1, 0, size - 1, tree);

    return tree;
}