#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
using Matrix = Graph;

bool isValid(const Graph &G, int row, int col, const Matrix &visited)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && G[row][col] == 1 && visited[row][col] == 0;
}

void DFS(Graph G, Matrix &visited, int row, int col)
{
    vector<int> posRows = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> posCols = {-1, 0, 1, -1, 1, -1, 0};

    visited[row][col] = 1;
    

    for (int i = 0; i < 8; ++i)
    {
        int newPosRow = row + posRows[i];
        int newPosCol = col + posCols[i];

        if(isValid(G, newPosRow, newPosCol, visited))
            DFS(G, visited, newPosRow, newPosCol);
    }
}

int countNumberIslands(Graph &G)
{
    Matrix visited(G.size(), vector<int>(G[0].size(), 0));
    int cantIslands = 0;

    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if (G[i][j] == 1 && visited[i][j] == 0)
            {
                ++cantIslands;
                DFS(G, visited, i, j);
            }
        }
    }

    return cantIslands;
}

int main()
{
    Graph G(5, vector<int>(5, 0));
    G[0] = {1, 1, 0, 0, 0};
    G[1] = {0, 1, 0, 0, 1};
    G[2] = {1, 0, 0, 1, 1};
    G[3] = {0, 0, 0, 0, 0};
    G[4] = {1, 0, 1, 1, 0};

    cout<<countNumberIslands(G);

    return 0;
}