#include <bits/stdc++.h>

using namespace std;

#define ENDL cout << "\n"

using Graph = vector<vector<int>>;
using Matrix = Graph;

vector<int> posRows = {-1, 0, 0, 1};
vector<int> posCols = {0, -1, 1, 0};

bool isValid(const Graph &G, const Matrix &visited, int row, int col, int color)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && visited[row][col] == 0 && G[row][col] != 0 && G[row][col] != color;
}

void DFS(Graph &G, Matrix &visited, int row, int col, int newColor)
{
    visited[row][col] = 1;
    G[row][col] = newColor;

    for (int i = 0; i < 4; ++i)
    {
        int newPosRows = row + posRows[i];
        int newPosCols = col + posCols[i];

        if (isValid(G, visited, newPosRows, newPosCols, newColor))
            DFS(G, visited, newPosRows, newPosCols, newColor);
    }
}

void floodFill(Graph &G, int newColor, pair<int, int> coordinates)
{
    Matrix visited(G.size(), vector<int>(G[0].size(), 0));
    DFS(G, visited, coordinates.first, coordinates.second, newColor);

    // for (int i = 0; i < G.size(); ++i)
    // {
    //     for (int j = 0; j < G[i].size(); ++j)
    //     {
    //         if (G[i][j] == 1 && visited[i][j] == 0)
    //         {
    //             DFS(G, visited, i, j, newColor);
    //         }
    //     }
    // }
}

void BFS(Graph &G, Matrix &visited, int row, int col, int newColor)
{
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    visited[row][col] = 1;
    G[row][col] = newColor;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newPosRows = par.first + posRows[i];
            int newPosCols = par.second + posCols[i];

            if (isValid(G, visited, newPosRows, newPosCols, newColor))
            {
                visited[newPosRows][newPosCols] = 1;
                G[newPosRows][newPosCols] = newColor;
                q.push({newPosRows, newPosCols});
            }
        }
    }
}

void floodFillBFS(Graph &G, int newColor, const pair<int, int> &coordinates)
{
    Matrix visited(G.size(), vector<int>(G[0].size(), 0));
    BFS(G, visited, coordinates.first, coordinates.second, newColor);
}

void printMatrix(const Graph &G)
{
    for (const auto &v : G)
    {
        for (const auto &elem : v)
            cout << elem << " ";

        cout << "\n";
    }
}

int main()
{
    Graph G(3, vector<int>(3, 0));
    G[0] = {1, 1, 1};
    G[1] = {1, 1, 0};
    G[2] = {1, 0, 1};
    auto GG = G;

    printMatrix(G);
    floodFill(G, 3, {1, 1});

    ENDL;

    printMatrix(G);

    ENDL;

    printMatrix(GG);

    ENDL;
    
    floodFillBFS(GG, 3, {1, 1});
    printMatrix(GG);


    return 0;
}