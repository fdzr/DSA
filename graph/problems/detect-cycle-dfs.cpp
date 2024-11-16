#include <bits/stdc++.h>

using namespace std;

using Graph = vector<list<int>>;

bool detectCycle(Graph &G, int source, vector<int> &visited, int parent)
{
    visited[source] = 1;
    for (const auto &v : G[source])
    {
        if (visited[v] == 0)
        {
            if (detectCycle(G, v, visited, source))
                return true;
        }
        else
        {
            if (parent != v)
                return true;
        }
    }

    return false;
}

void addEdge(Graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    Graph G(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);
    addEdge(G, 3, 4);
    vector<int> visited(5, 0);

    cout << boolalpha << detectCycle(G, 0, visited, -1);

    return 0;
}