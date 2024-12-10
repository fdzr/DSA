#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

bool isValid(Matrix &G, Matrix &visited, int row, int col) {
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() &&
           visited[row][col] == 0 && G[row][col] == 1;
}

void DFS(Matrix &G, Matrix &visited, int row, int col, int &cont) {
    visited[row][col] = 1;
    ++cont;

    vector<pair<int, int>> directions = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                                         {0, 1},  {1, 1},   {1, 0},  {-1, 1}};

    for (const auto &coor : directions) {
        int newRow = coor.first + row;
        int newCol = coor.second + col;

        if (isValid(G, visited, newRow, newCol)) DFS(G, visited, newRow, newCol, cont);
    }
}

int maxAreaIsland(Matrix &G) {
    Matrix visited(G.size(), vector<int>(G[0].size(), 0));
    int maxArea = 0;

    for (int i = 0; i < G.size(); ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            int cont = 0;
            if (visited[i][j] == 0 && G[i][j] == 1) {
                DFS(G, visited, i, j, cont);
                cout << cont << "\n";
                if (cont > maxArea) maxArea = cont;
            }
        }
    }
    return maxArea;
}

int main() {
    Matrix G(5);
    G[0] = {1, 0, 0, 0, 1, 0, 0};
    G[1] = {0, 1, 0, 0, 1, 1, 0};
    G[2] = {1, 1, 0, 0, 0, 0, 0};
    G[3] = {1, 0, 0, 1, 1, 0, 0};
    G[4] = {1, 0, 0, 1, 0, 1, 1};

    cout << maxAreaIsland(G);

    return 0;
}