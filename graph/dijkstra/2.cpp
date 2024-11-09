#include <bits/stdc++.h>

using namespace std;

using Graph = vector<list<pair<int, int>>>;
int V = 9;

int getMinimumDistance(vector<int> &visited, const vector<int> &distance)
{
    int minValue = INT_MAX, u = -1;
    for (int v = 0; v < V; ++v)
    {
        if (visited[v] == 0 && distance[v] < minValue)
        {
            minValue = distance[v];
            u = v;
        }
    }

    return u;
}

void dijkstra(Graph &G, int source)
{
    vector<int> visited(V, 0);
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < V; ++i)
    {
        int u = getMinimumDistance(visited, distance);

        visited[u] = 1;

        for (const auto &item : G[u])
        {
            if (visited[item.first] == 0 && distance[u] + item.second < distance[item.first])
                distance[item.first] = distance[u] + item.second;
        }
    }

    for (int i = 0; i < V; ++i)
        cout<<i<<": "<<distance[i]<<"\n";
    
}

void addEdge(Graph &G, int u, int v, int w)
{
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
}

int main()
{
    Graph G(V);
    addEdge(G, 0, 1, 4);
    addEdge(G, 0, 7, 8);
    addEdge(G, 1, 2, 8);
    addEdge(G, 1, 7, 11);
    addEdge(G, 2, 3, 7);
    addEdge(G, 2, 8, 2);
    addEdge(G, 2, 5, 4);
    addEdge(G, 3, 4, 9);
    addEdge(G, 3, 5, 14);
    addEdge(G, 4, 5, 10);
    addEdge(G, 5, 6, 2);
    addEdge(G, 6, 7, 1);
    addEdge(G, 6, 8, 6);
    addEdge(G, 7, 8, 7);

    dijkstra(G, 0);

    return 0;
}