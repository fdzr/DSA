#include <bits/stdc++.h>

// adjacency matrix

using namespace std;

using Graph = vector<vector<int>>;

void DFS(Graph G, vector<int> &visited, int source)
{
    visited[source] = 1;
    cout << source << " ";

    for (int i = 0; i < G[source].size(); ++i)
    {
        if (G[source][i] == 1 && visited[i] == 0)
        {
            DFS(G, visited, i);
        }
    }
}

void addEdge(Graph &G, int u, int v)
{
    assert(u != v);

    G[u][v] = 1;
    G[v][u] = 1;
}

int main()
{
    Graph G(5, vector<int>(5, 0));
    vector<int> visited(5, 0);

    addEdge(G, 0, 1);
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 4);
    addEdge(G, 3, 4);

    DFS(G, visited, 0);

    return 0;
}