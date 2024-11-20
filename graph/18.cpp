#include <bits/stdc++.h>

using namespace std;

using Grid = vector<vector<int>>;
using Matrix = Grid;

bool isValid(const Grid &G, const Matrix &visited, int row, int col, int oldColor)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && visited[row][col] == 0 && G[row][col] == oldColor;
}

void BFS(Grid &G, int row, int col, int color)
{
    Matrix visited(G.size(), vector<int>(G[0].size(), 0));
    queue<pair<int, int>> q;
    q.push({row, col});
    int oldColor = G[row][col];

    vector<pair<int, int>> adj = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    while (!q.empty())
    {
        auto coordinate = q.front();
        q.pop();

        visited[coordinate.first][coordinate.second] = 1;
        G[coordinate.first][coordinate.second] = color;

        for (int i = 0; i < adj.size(); ++i)
        {
            int newPosRow = coordinate.first + adj[i].first;
            int newPosCol = coordinate.second + adj[i].second;

            if (isValid(G, visited, newPosRow, newPosCol, oldColor))
                q.push({newPosRow, newPosCol});
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    BFS(image, sr, sc, color);
    return image;
}

void printMatrix(const Grid &G)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
            cout << G[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    Grid G(3);
    G[0] = {1, 1, 1};
    G[1] = {3, 1, 0};
    G[2] = {1, 0, 1};

    printMatrix(G);
    
    printf("\n");

    printMatrix(floodFill(G, 1, 1, 2));

    return 0;
}