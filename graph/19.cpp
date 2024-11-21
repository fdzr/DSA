#include <bits/stdc++.h>

using namespace std;

using Grid = vector<vector<int>>;
using Matrix = Grid;

bool isValid(const Grid &G, const Matrix &visited, int row, int col)
{
    return row >= 0 && row < G.size() && col >= 0 and col < G[0].size() && visited[row][col] == 0 && G[row][col] == 1;
}

void DFS(const Grid &G, Matrix &visited, int row, int col, int &cont)
{
    visited[row][col] = 1;
    vector<pair<int, int>> coordinates = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (const auto &item : coordinates)
    {
        int newPosRow = row + item.first;
        int newPosCol = col + item.second;

        if (isValid(G, visited, newPosRow, newPosCol))
            DFS(G, visited, newPosRow, newPosCol, ++cont);
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    Matrix visited(grid.size(), vector<int>(grid[0].size(), 0));
    int max_area = 0;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if(visited[i][j] == 0 && grid[i][j] == 1) {
                int cont = 1;
                DFS(grid, visited, i, j, cont);

                if (cont > max_area)
                    max_area = cont;
            }
        }
    }

    return max_area;
}

int main()
{
    Grid G(8);
    G[0] = {0,0,1,0,0,0,0,1,0,0,0,0,0};
    G[1] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    G[2] = {0,1,1,0,1,0,0,0,0,0,0,0,0};
    G[3] = {0,1,0,0,1,1,0,0,1,0,1,0,0};
    G[4] = {0,1,0,0,1,1,0,0,1,1,1,0,0};
    G[5] = {0,0,0,0,0,0,0,0,0,0,1,0,0};
    G[6] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    G[7] = {0,0,0,0,0,0,0,1,1,0,0,0,0};

    cout<< maxAreaOfIsland(G);

    return 0;
}