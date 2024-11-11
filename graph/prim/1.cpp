// optimized Prim

#include <bits/stdc++.h>

using namespace std;

using Graph = vector<list<pair<int, int>>>;

void prim(const Graph &G)
{
    vector<int> visited(G.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty())
    {
        auto weigthedEdge = pq.top();
        pq.pop();

        if (visited[weigthedEdge.second] == 1)
            continue;

        visited[weigthedEdge.second] = 1;
        sum += weigthedEdge.first;

        for (const auto &item : G[weigthedEdge.second])
        {
            if (visited[item.second] == 0)
            {
                pq.push(item);
            }
        }
    }

    cout << sum;
}

void addEdge(Graph &G, int u, int v, int w)
{
    G[u].push_back({w, v});
    G[v].push_back({w, u});
}

int main()
{
    Graph G(6);
    addEdge(G, 0, 1, 12);
    addEdge(G, 0, 2, 8);
    addEdge(G, 1, 2, 9);
    addEdge(G, 1, 3, 22);
    addEdge(G, 1, 5, 11);
    addEdge(G, 2, 3, 16);
    addEdge(G, 2, 5, 14);
    addEdge(G, 3, 4, 15);
    addEdge(G, 3, 5, 18);
    addEdge(G, 4, 5, 3);

    prim(G);
    cout << "\n";

    G.clear();

    G.resize(9);
    addEdge(G, 0, 1, 7);
    addEdge(G, 0, 8, 15);

    addEdge(G, 1, 2, 5);

    addEdge(G, 2, 3, 4);
    addEdge(G, 2, 4, 2);
    addEdge(G, 2, 6, 3);

    addEdge(G, 3, 4, 1);
    addEdge(G, 3, 5, 9);

    addEdge(G, 5, 6, 5);
    addEdge(G, 5, 7, 12);

    addEdge(G, 6, 8, 6);

    addEdge(G, 7, 8, 10);

    prim(G);

    return 0;
}
