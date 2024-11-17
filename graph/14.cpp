#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;
using Grid = vector<vector<char>>;

bool isValid(const Grid &G, const Matrix &visited, int row, int col)
{

    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && visited[row][col] == 0 && G[row][col] == '1';
}

void DFS(Grid &G, Matrix &visited, pair<int, int> coor)
{
    vector<int> posRow = {-1, 0, 0, 1};
    vector<int> posCol = {0, -1, 1, 0};

    visited[coor.first][coor.second] = 1;

    for (int i = 0; i < posRow.size(); ++i)
    {
        int newPosRow = coor.first + posRow[i];
        int newPosCol = coor.second + posCol[i];

        if (isValid(G, visited, newPosRow, newPosCol))
            DFS(G, visited, {newPosRow, newPosCol});
    }
}

int numIslands(vector<vector<char>> &grid)
{
    Matrix visited(grid.size(), vector<int>(grid[0].size(), 0));
    int cont = 0;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (visited[i][j] == 0 && grid[i][j] == '1')
            {
                cont++;
                DFS(grid, visited, {i, j});
            }
        }
    }

    return cont;
}

int main()
{
    Grid G(4);
    G[0] = {'1', '1', '0', '0', '0'};
    G[1] = {'1', '1', '0', '0', '0'};
    G[2] = {'0', '0', '1', '0', '0'};
    G[3] = {'0', '0', '0', '1', '1'};

    cout << numIslands(G);

    return 0;
}