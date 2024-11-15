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
            rank[i] = 0;
        }
    }

    ~DSU()
    {
        delete rank;
        delete parent;
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
                parent[x] = y;
            else if (rank[x] > rank[y])
                parent[y] = x;
            else
            {
                parent[y] = x;
                rank[x] += 1;
            }
        }
    }
};

struct hashType
{
    int operator()(const pair<int, int>& T) const
    {
        return hash<int>()(T.first) ^ (hash<int>()(T.second) << 1);
    }
};

bool detectCycle(const Graph &G)
{
    DSU ds(G.size());
    unordered_set<pair<int, int>, hashType> visited;

    for (int u = 0; u < G.size(); ++u)
    {
        for (const auto &edge : G[u])
        {
            int x = ds.find(u);
            int y = ds.find(edge);

            if (visited.find({u, edge}) == visited.end() && visited.find({edge, u}) == visited.end() && x == y)
                return true;

            ds.unite(x, y);
            visited.insert({u, edge});
        }
    }

    return false;
}

void addEdge(Graph &G, int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    Graph G(6);
    // addEdge(G, 0, 1);
    // addEdge(G, 1, 2);
    // addEdge(G, 1, 4);
    // addEdge(G, 2, 3);
    // addEdge(G, 4, 5);
    // addEdge(G, 5, 6);
    // // addEdge(G, 6, 1);
    // addEdge(G, 5, 7);

    addEdge(G, 0, 1);
    addEdge(G, 0, 2);

    addEdge(G, 2, 3);
    addEdge(G, 2, 4);
    addEdge(G, 2, 5);

    addEdge(G, 4, 5);

    cout << boolalpha << detectCycle(G);

    return 0;
}
