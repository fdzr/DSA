#include <bits/stdc++.h>

using namespace std;

using Graph = vector<list<int>>;

struct DSU
{
    int *rank, *parent;

    DSU(int V)
    {
        rank = new int[V];
        parent = new int[V];

        for (int i = 0; i < V; ++i)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int u)
    {
        if (parent[u] == -1)
            return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v)
    {
        int x = find(u);
        int y = find(v);

        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                parent[x] = y;
                rank[y] += 1;
            }
            else if (rank[x] > rank[y])
            {
                parent[y] = x;
                rank[x] += 1;
            }
            else
            {
                parent[y] = x;
                rank[x] += 1;
            }
        }
    }
};

bool detectCycle(Graph G, int source)
{
    queue<int> q;
    q.push(source);
    vector<int> visited(8, 0);
    visited[source] = 1;

    DSU ds(G.size());

    for(int u = 0; G.size(); ++u)

    return true;
}

void addEdge(Graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    Graph G(8);
    addEdge(G, 0, 1);
    addEdge(G, 1, 2);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 4, 5);
    addEdge(G, 5, 6);
    // addEdge(G, 6, 1);
    addEdge(G, 5, 7);

    cout << boolalpha << detectCycle(G, 0);

    return 0;
}