#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
using Graph = vector<vector<int>>;

void floydWarshall(Graph &G)
{
    int V = G.size();

    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (G[i][j] > G[i][k] + G[k][j] && G[i][k] != INF && G[k][j] != INF)
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
}

void printMatrix(const Graph &G)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            cout<<G[i][j] << " ";
        }

        cout<<"\n";
    }
}

int main()
{
    vector<vector<int>> G = {{0, 3, INF, 5},
                             {2, 0, INF, 4},
                             {INF, 1, 0, INF},
                             {INF, INF, 2, 0}};

    floydWarshall(G);
    printMatrix(G);

    return 0;
}