#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

void BFS(Graph G, int source, vector<int> &visited)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout<<vertex<<" ";

        for (int i = 0; i < G[vertex].size(); ++i)
        {
            if (visited[G[vertex][i]] == 0)
            {
                q.push(G[vertex][i]);
                visited[G[vertex][i]] = 1;
            }
        }
    }
}

void BFSDisconnected(Graph &G)
{
    vector<int> visited(G.size(), 0);

    for (int i = 0; i < G.size(); ++i)
    {
        if (visited[i] == 0)
        {
            BFS(G, i, visited);
        }
    }
}

void addEdge(Graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    Graph G(9);
    addEdge(G, 0, 3);
    addEdge(G, 0, 5);
    addEdge(G, 1, 5);
    addEdge(G, 1, 8);
    addEdge(G, 5, 8);

    addEdge(G, 4, 6);
    addEdge(G, 6, 7);

    BFSDisconnected(G);
    

    return 0;
}