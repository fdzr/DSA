#include <bits/stdc++.h>

using namespace std;

struct weightedEdge
{
    int u, v, w;

    bool operator<(const weightedEdge &other) const
    {
        return w < other.w;
    }
};

using Graph = vector<weightedEdge>;

void addEdge(Graph &G, int u, int v, int w)
{
    G.push_back(weightedEdge{u, v, w});
}

struct DSU
{
    int *parent, *rank;

    DSU(int V)
    {
        parent = new int[V];
        rank = new int[V];

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

void kruskal(Graph &G, int V)
{
    sort(G.begin(), G.end());
    int sum = 0;
    DSU dsu(V);

    for (const auto &edge : G)
    {
        int x = dsu.find(edge.u);
        int y = dsu.find(edge.v);

        if (x != y)
        {
            dsu.unite(x, y);
            sum += edge.w;
            cout << "Edge included in MST: (" << edge.u <<
                ", " << edge.v << ") with weight " << edge.w << endl;
        }
    }

    cout << sum;
}

int main()
{
    int V = 9;

    Graph G;
    addEdge(G, 0, 1, 7);
    addEdge(G, 0, 8, 15);
    addEdge(G, 1, 2, 5);
    addEdge(G, 2, 4, 2);
    addEdge(G, 2, 3, 4);
    addEdge(G, 2, 6, 3);
    addEdge(G, 3, 4, 1);
    addEdge(G, 3, 5, 9);
    addEdge(G, 5, 6, 5);
    addEdge(G, 5, 7, 12);
    addEdge(G, 6, 8, 6);
    addEdge(G, 7, 8, 10);

    kruskal(G, V);

    return 0;
}