#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

void BFS(graph G, int source)
{
    vector<int> visited(G.size(), false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout<<vertex<<" ";

        for (const int &elem : G[vertex])
        {
            if (!visited[elem])
            {
                q.push(elem);
                visited[elem] = true;
            }
        }
    }
}

void addEdge(graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    graph G(5);
    addEdge(G, 0, 1);
    addEdge(G, 0, 3);
    addEdge(G, 1, 3);
    addEdge(G, 1, 2);
    addEdge(G, 2, 4);
    addEdge(G, 3, 4);
    BFS(G, 0);

    return 0;
}