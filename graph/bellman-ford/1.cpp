#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

using Graph = vector<vector<pair<int, int>>>;

vector<int> bellmanFord(Graph &G, int source)
{
    int V = G.size();
    vector<int> distance(V, INF);
    distance[source] = 0;

    for (int v = 0; v < V; ++v)
    {
        for (int i = 0; i < G.size(); ++i)
        {
            for (const auto &edge : G[i])
            {
                int u = edge.first;
                int w = edge.second;

                if (distance[edge.first] > distance[i] + edge.second)
                {
                    if (v == V - 1)
                        return {-1};
                    distance[edge.first] = distance[i] + edge.second;
                }
            }
        }
    }

    return distance;
}

void addEdge(Graph &G, int source, int dest, int w, bool directed = false)
{
    G[source].push_back(make_pair(dest, w));
    if (!directed)
    {
        G[dest].push_back(make_pair(source, w));
    }
}

void printDistance(vector<int> distance)
{
    for (int i = 0; i < distance.size(); ++i)

        cout << i << ": " << distance[i] << "\n";
}

int main()
{
    Graph G(5);
    addEdge(G, 0, 1, 4, true);
    addEdge(G, 0, 2, 2, true);
    addEdge(G, 1, 2, 3, true);
    addEdge(G, 1, 3, 2, true);
    addEdge(G, 1, 4, 3, true);
    addEdge(G, 2, 1, 1, true);
    addEdge(G, 2, 3, 4, true);
    addEdge(G, 2, 4, 5, true);
    addEdge(G, 4, 3, -5, true);

    auto distance = bellmanFord(G, 0);
    printDistance(distance);
    cout<<"\n";

    G.clear();

    G.resize(5);
    addEdge(G, 0, 1, 2, true);
    addEdge(G, 1, 2, 2, true);
    addEdge(G, 1, 3, 1, true);
    addEdge(G, 2, 3, -4, true);
    addEdge(G, 3, 1, 1, true);
    addEdge(G, 3, 4, 3, true);

    distance = bellmanFord(G, 0);
    printDistance(distance);

    return 0;
}