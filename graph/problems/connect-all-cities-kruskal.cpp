#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

struct sol
{
    int u;
    int v;
    int w;
};

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
            rank[i] = 0;
        }
    }

    ~DSU()
    {
        delete parent;
        delete rank;
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
                rank[x]++;
            }
        }
    }
};

vector<sol> createEdgeList(const Graph &G)
{
    vector<sol> edgeList;

    for (int row = 0; row < G.size(); ++row)
    {
        for (int col = 0; col < G[row].size(); ++col)
        {
            if (G[row][col] != 0 && row < col)
                edgeList.push_back(sol{row, col, G[row][col]});
        }
    }

    return edgeList;
}

int kruskal(Graph G)
{
    vector<sol> edgeList = createEdgeList(G);
    sort(edgeList.begin(), edgeList.end(), [](const sol &a, const auto &b)
         { return a.w < b.w; });

    DSU ds(G.size());
    int sum = 0;

    for (const auto &weightedEdge : edgeList)
    {
        int x = ds.find(weightedEdge.u);
        int y = ds.find(weightedEdge.v);

        if (x != y) {
            ds.unite(x, y);
            sum += weightedEdge.w;
        }
    }

    return sum;
}

int main()
{
    Graph G(5, vector<int>(5, 0));
    G[0] = {0, 1, 2, 3, 4};
    G[1] = {1, 0, 5, 0, 7};
    G[2] = {2, 5, 0, 6, 0};
    G[3] = {3, 0, 6, 0, 0};
    G[4] = {4, 7, 0, 0, 0};

    cout<< kruskal(G);

    return 0;
}