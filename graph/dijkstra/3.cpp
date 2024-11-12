#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
typedef vector<list<pair<int, int>>> Graph;
using pi = pair<int, int>;

void dijkstra(const Graph &G, int source)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(G.size(), INF);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto weightedEdge = pq.top();
        pq.pop();

        for (const auto &we : G[weightedEdge.second])
        {
            if (dist[we.second] > dist[weightedEdge.second] + we.first)
            {
                dist[we.second] = dist[weightedEdge.second] + we.first;
                pq.push({dist[we.second], we.second});
            }
        }
    }

    for(int i = 0; i < G.size(); ++i)
        cout<<i<<": "<<dist[i]<<"\n";
}

void addEdge(Graph &G, int u, int v, int w)
{
    G[u].push_back({w, v});
    G[v].push_back({w, u});
}

int main()
{
    Graph G(9);
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