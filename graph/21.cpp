#include <bits/stdc++.h>

using namespace std;

using board = vector<vector<int>>;

bool isValid(board& G, board& visited, int row, int col) {
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() &&
           visited[row][col] == 0;
}

bool belongsToComponent(const board& G, int row, int col, int color) {
    return G[row][col] == color;
}

bool isBorder(const board& G, int row, int col) {
    return row == 0 || row == G.size() - 1 || col == 0 || col == G[0].size() - 1;
}

vector<vector<int>> colorBorder(board& grid, int row, int col, int color) {
    int colorStartingPoint = grid[row][col];
    board visited(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> q;
    q.push({row, col});

    vector<pair<int, int>> coordinates{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    while (!q.empty()) {
        auto coor = q.front();
        q.pop();
        visited[coor.first][coor.second] = 1;

        if (isBorder(grid, coor.first, coor.second))
            grid[coor.first][coor.second] = color;

        for (int i = 0; i < coordinates.size(); ++i) {
            int newRow = coor.first + coordinates[i].first;
            int newCol = coor.second + coordinates[i].second;

            if (isValid(grid, visited, newRow, newCol)) {
                if (belongsToComponent(grid, newRow, newCol, colorStartingPoint))
                    q.push({newRow, newCol});
                else {
                    grid[coor.first][coor.second] = color;
                }
            }
        }
    }

    return grid;
}

void printMatrix(const board& G) {
    for (int i = 0; i < G.size(); ++i) {
        for (int j = 0; j < G[i].size(); ++j) printf("%d ", G[i][j]);
        printf("\n");
    }

    printf("\n");
}

int main() {
    board G(2);
    G[0] = {1, 1};
    G[1] = {1, 2};
    int color = 3;
    int row = 0;
    int col = 0;

    printMatrix(colorBorder(G, row, col, color));

    G.resize(2);
    G[0] = {1, 2, 2};
    G[1] = {2, 3, 2};

    row = 0, col = 1, color = 3;

    printMatrix(colorBorder(G, row, col, color));

    G.resize(3);
    G[0] = {1, 1, 1};
    G[1] = {1, 1, 4};
    G[2] = {1, 1, 1};
    row = 1, col = 1, color = 2;

    printMatrix(colorBorder(G, row, col, color));

    return 0;
}