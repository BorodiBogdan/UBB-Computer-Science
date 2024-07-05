#include <iostream>
#include <vector>
#include <stack>
#include <vector>
#define Nmax 1000001
using namespace std;

int Id[Nmax], LowLink[Nmax];
bool isArticulationPoint[Nmax];
vector<int> V[Nmax];
vector<pair<int, int>> BridgesList;

void criticalPoints(int root, int vertex, int parentVertex, int &id, int &ans)
{
    Id[vertex] = LowLink[vertex] = id++;
    int edges = 0;

    for (auto newVertex : V[vertex])
        if (newVertex == parentVertex)
            continue;
        else if (!Id[newVertex])
        {
            edges++;
            criticalPoints(root, newVertex, vertex, id, ans);
            LowLink[vertex] = min(LowLink[vertex], LowLink[newVertex]);

            // vertex is either the starting of a cycle either a component of a bridge
            // not every vertex from a bridge is an articulation point
            // it is an articlation point just if it has more then one conection
            if (Id[vertex] <= LowLink[newVertex])
            {
                isArticulationPoint[vertex] = true;

                // if we want to find the biconex components
                // we need to keep track of the visited nodes in a stack
                // every time we find that vertex is an articulation point between
                // two separate components
                // we found a maximal biconex component)
                // we pop the stack to reconstruct the component until we find the
                // vertex we started the search from(critical vertex always if it is not
                // the source vertex, then it may be just a vertex in a cycle)
            }
        }
        else
            LowLink[vertex] = min(Id[vertex], LowLink[newVertex]);

    if (root == vertex)
        isArticulationPoint[vertex] = edges > 1;
}

// LowLink -> Lowest id reacheable from a node when performing a DFS
// Id -> id of the vertex

void Bridges(int vertex, int parentVertex, int &id)
{
    Id[vertex] = LowLink[vertex] = id++;
    int edges = 0;

    for (auto newVertex : V[vertex])
        if (newVertex == parentVertex)
            continue;
        else if (!Id[newVertex])
        {
            edges++;
            Bridges(newVertex, vertex, id);
            LowLink[vertex] = min(LowLink[vertex], LowLink[newVertex]);

            // it means that newVertex can not reach vertex when performing a dfs
            // then if ve remove the edge vertex - newVertex there is no path
            // between them -> we have two separate conex components
            if (Id[vertex] < LowLink[newVertex])
                BridgesList.push_back({vertex, newVertex});
        }
        else
            LowLink[vertex] = min(Id[vertex], LowLink[newVertex]);
}

int main()
{

    return 0;
}