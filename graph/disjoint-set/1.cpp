#include <bits/stdc++.h>

using namespace std;

struct DS
{
    int *parent;
    int *rank;

    DS(int V)
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
            return -1;

        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v)
    {
        int x = find(u);
        int y = find(v);

        if(x != y) {
            if(rank[x] < rank[y])
                parent[x] = y;
            else if(rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[y] = x;
                rank[x] += 1;
            }
        }
    }
};

int main()
{

    return 0;
}