#include <bits/stdc++.h>
// https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/

using namespace std;

using Graph = vector<vector<int>>;
using Matrix = Graph;

vector<int> posRows = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> posCols = {-1, 0, 1, -1, 1, -1, 0};

bool isValid(const Graph &G, int row, int col, const Matrix &visited)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && G[row][col] == 1 && visited[row][col] == 0;
}

void DFS(Graph G, Matrix &visited, int row, int col)
{
    visited[row][col] = 1;

    for (int i = 0; i < 8; ++i)
    {
        int newPosRow = row + posRows[i];
        int newPosCol = col + posCols[i];

        if (isValid(G, newPosRow, newPosCol, visited))
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

void BFS(Graph G, Matrix &visited, int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int newPosRow = pos.first + posRows[i];
            int newPosCol = pos.second + posCols[i];
            if (isValid(G, newPosRow, newPosCol, visited))
            {
                q.push({newPosRow, newPosCol});
                visited[newPosRow][newPosCol] = 1;
            }
        }
    }
}

int countNumberIslandsUsingBFS(Graph &G)
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
                BFS(G, visited, i, j);
            }
        }
    }

    return cantIslands;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Graph G(5, vector<int>(5, 0));
    G[0] = {1, 1, 0, 0, 0};
    G[1] = {0, 1, 0, 0, 1};
    G[2] = {1, 0, 0, 1, 1};
    G[3] = {0, 0, 0, 0, 0};
    G[4] = {1, 0, 1, 1, 0};

    cout << countNumberIslands(G) << "\n";
    cout << countNumberIslandsUsingBFS(G) << "\n";

    return 0;
}