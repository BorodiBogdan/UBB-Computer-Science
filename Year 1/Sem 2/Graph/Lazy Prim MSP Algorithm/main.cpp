#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#define Nmax 1000001
using namespace std;

ifstream fin("prim.in");
ofstream fout("prim.out");

bool isMarked[Nmax];

struct Edge
{
    int x, y, c;
};

class mycomparison
{
public:
    bool operator()(const Edge &a, const Edge &b) const
    {
        return a.c > b.c;
    }
};

typedef priority_queue<Edge, vector<Edge>, mycomparison> primPriorityQueue;
primPriorityQueue Q;
vector<pair<int, int>> V[Nmax];
int Dad[Nmax];

void addEdges(primPriorityQueue &Q, int vertex)
{
    isMarked[vertex] = true;

    for (auto newVertex : V[vertex])
    {
        Edge newEdge = {vertex, newVertex.first, newVertex.second};
        if (isMarked[newEdge.y] == false)
            Q.push(newEdge);
    }
}

int main()
{
    int n, m;

    fin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int x, y, c;

        fin >> x >> y >> c;

        V[x].push_back({y, c});
        V[y].push_back({x, c});
    }

    addEdges(Q, 1);
    vector<Edge> MST;
    int minimumSum = 0;

    while (!Q.empty())
    {
        Edge topEdge = Q.top();
        Q.pop();
        int v1 = topEdge.x;
        int v2 = topEdge.y;
        int cost = topEdge.c;

        if (!isMarked[v2])
        {
            MST.push_back(topEdge);
            minimumSum += cost;
            addEdges(Q, v2);
            Dad[v2] = v1;
        }
    }

    fout << minimumSum << "\n";

    for (auto edge : MST)
        fout << edge.x << " " << edge.y << "\n";
}