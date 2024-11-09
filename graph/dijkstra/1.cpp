#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
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

        for (int v = 0; v < V; ++v)
        {
            if (visited[v] == 0 && G[u][v] != 0 && distance[u] + G[u][v] < distance[v])
            {
                distance[v] = distance[u] + G[u][v];
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        cout<<i<<": "<<distance[i]<<"\n";
    }
}

int main()
{
    Graph G = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
               {4, 0, 8, 0, 0, 0, 0, 11, 0},
               {0, 8, 0, 7, 0, 4, 0, 0, 2},
               {0, 0, 7, 0, 9, 14, 0, 0, 0},
               {0, 0, 0, 9, 0, 10, 0, 0, 0},
               {0, 0, 4, 14, 10, 0, 2, 0, 0},
               {0, 0, 0, 0, 0, 2, 0, 1, 6},
               {8, 11, 0, 0, 0, 0, 1, 0, 7},
               {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(G, 0);

    return 0;
}