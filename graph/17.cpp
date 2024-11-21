#include <bits/stdc++.h>

using namespace std;

using Grid = vector<vector<int>>;
using Matrix = Grid;

void DFS(const Grid &G, Matrix &visited, int row, int col, int &cont) {
    visited[row][col] = 1;
    vector<pair<int, int>> coordinates = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (const auto &item : coordinates) {
        int newPosRow = row + item.first;
        int newPosCol = col + item.second;

        if (newPosRow < 0 || newPosRow >= G.size() || newPosCol < 0 || newPosCol >= G[0].size())
            ++cont;
        else if (G[newPosRow][newPosCol] == 0)
            ++cont;
        else if (visited[newPosRow][newPosCol] == 0)
            DFS(G, visited, newPosRow, newPosCol, cont);
    }
}

int islandPerimeter(vector<vector<int>> &grid) {
    Matrix visited(grid.size(), vector<int>(grid[0].size(), 0));
    int cont = 0;

    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[row].size(); ++col) {
            if (visited[row][col] == 0 && grid[row][col] == 1) {
                DFS(grid, visited, row, col, cont);
                return cont;
            }
        }
    }

    return cont;
}

int main() {
    Grid G(4);
    G[0] = {0, 1, 0, 0};
    G[1] = {1, 1, 1, 0};
    G[2] = {0, 1, 0, 0};
    G[3] = {1, 1, 0, 0};

    cout << islandPerimeter(G);

    return 0;
}