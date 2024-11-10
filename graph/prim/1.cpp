#include <bits/stdc++.h>

using namespace std;

using Graph = vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>>;

void prim(const Graph &G)
{
    vector<int> visited(G.size(), 0);
    int sum = 0;
    queue<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> q;
    q.push(G[0]);
    visited[0] = 1;

    while (!q.empty())
    {
        auto setVertex = q.front();
        q.pop();

        while (!setVertex.empty())
        {
            auto weigthedEdge = setVertex.top();
            setVertex.pop();

            if (visited[weigthedEdge.second] == 0)
            {
                q.push(G[weigthedEdge.second]);
                visited[weigthedEdge.second] = 1;
                sum += weigthedEdge.first;
                break;
            }
        }
    }

    cout << sum;
}

void addEdge(Graph &G, int u, int v, int w)
{
    G[u].push(make_pair(w, v));
    G[v].push(make_pair(w, u));
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

    return 0;
}