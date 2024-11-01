#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void DFSUtil(const Graph &G, vector<int> &visited, int source)
{
    visited[source] = true;
    cout << source << " ";

    for (const auto &elem : G[source])
    {
        if (visited[elem] == 0)
        {
            DFSUtil(G, visited, elem);
            // visited[elem] = 1;
        }
    }
}

void DFSDisconnected(const Graph &G, int &connectedComponets)
{
    vector<int> visited(G.size(), 0);
    for (int i = 0; i < G.size(); ++i)
    {
        if (visited[i] == 0)
        {
            ++connectedComponets;
            DFSUtil(G, visited, i);
        }
    }
}

void DFS(Graph G, int source)
{
    vector<int> visited(G.size(), 0);
    DFSUtil(G, visited, source);
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
    addEdge(G, 0, 3);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 4);
    addEdge(G, 3, 4);

    DFS(G, 0);

    cout << "\n";

    G.clear();

    G.resize(9);
    addEdge(G, 0, 3);
    addEdge(G, 0, 5);
    addEdge(G, 1, 5);
    addEdge(G, 1, 8);
    addEdge(G, 5, 8);

    addEdge(G, 4, 6);
    addEdge(G, 6, 7);

    int connectedComponents = 0;
    DFSDisconnected(G, connectedComponents);
    cout<<"\n"<<connectedComponents;

    return 0;
}