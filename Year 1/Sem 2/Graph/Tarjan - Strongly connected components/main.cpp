#include <iostream>
#include <vector>
#include <stack>
#define Nmax 1000001
using namespace std;

bool onStack[Nmax];
vector<int> V[Nmax];
int Id[Nmax], LowLink[Nmax];
stack<int> S;
int cnt;

void tarjanStronglyConnectedComponents(int vertex, int &id)
{
    S.push(vertex);
    onStack[vertex] = true;
    Id[vertex] = LowLink[vertex] = id++;

    for (int newVertex : V[vertex])
    {
        if (Id[newVertex] == 0)
        {
            tarjanStronglyConnectedComponents(newVertex, id);
        }
        if (onStack[newVertex] == 1)
            LowLink[vertex] = min(LowLink[newVertex], LowLink[vertex]);
    }

    if (LowLink[vertex] == Id[vertex])
    {
        cnt++;
        int popedVertex = -1;

        while (S.size() > 0 && popedVertex != vertex)
        {
            popedVertex = S.top();
            LowLink[popedVertex] = LowLink[vertex];
            S.pop();
            onStack[popedVertex] = false;
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
    }

    int id = 0;

    for (int i = 1; i <= n; ++i)
        if (Id[i] == 0)
        {
            tarjanStronglyConnectedComponents(i, id);
        }

    cout << cnt;
}