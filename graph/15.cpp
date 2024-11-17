#include <bits/stdc++.h>

using namespace std;

using Grid = vector<vector<int>>;
using Matrix = Grid;

struct sol
{
    pair<int, int> coordinates;
    int time;
};

bool isValid(Grid &G, Matrix &visited, int row, int col)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && visited[row][col] == 0 && G[row][col] == 1;
}

int BFS(Grid &G, Matrix &visited, queue<sol> &q)
{
    vector<int> posRows = {-1, 0, 0, 1};
    vector<int> posCols = {0, -1, 1, 0};
    int time = 0;

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        time = v.time;

        visited[v.coordinates.first][v.coordinates.second] = 1;

        for (int i = 0; i < 4; ++i)
        {
            int newPosRows = v.coordinates.first + posRows[i];
            int newPosCols = v.coordinates.second + posCols[i];

            if (isValid(G, visited, newPosRows, newPosCols))
            {
                G[newPosRows][newPosCols] = 2;
                q.push({{newPosRows, newPosCols}, time + 1});
            }
        }
    }

    return time;
}

bool checkMatrix(const Grid &G, bool checkFreshFruit, bool checkRottenFruit)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if (checkFreshFruit && G[i][j] == 1)
                return true;
            if (checkRottenFruit && G[i][j] == 2)
                return true;
        }
    }

    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    queue<sol> q;
    Matrix visited(grid.size(), vector<int>(grid[0].size(), 0));
    bool freshFruit = false;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 2)
                q.push({{i, j}, 0});
        }
    }

    if (checkMatrix(grid, false, true) && checkMatrix(grid, true, false) == false)
        return 0;
    if (checkMatrix(grid, true, false) && checkMatrix(grid, false, true) == false)
        return -1;

    int answer = BFS(grid, visited, q);
    if (checkMatrix(grid, true, false))
        return -1;

    return answer;
}

int main()
{
    Grid G(1);
    G[0] = {0, 2};
    // G[1] = {0, 1, 1};
    // G[2] = {1, 0, 1};
    cout<<orangesRotting(G);

    return 0;
}