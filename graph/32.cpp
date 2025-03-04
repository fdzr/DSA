#include <bits/stdc++.h>

using namespace std;

template <integral T>
using matrix = vector<vector<T>>;

bool isValid(const matrix<int>& grid, int row, int col, const matrix<int>& visited) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
           visited[row][col] == 0 && grid[row][col] > 0;
}

int BFS(matrix<int>& grid, matrix<int>& visited, int row, int col) {
    queue<pair<int, int>> q;
    q.emplace(row, col);
    visited[row][col] = 1;
    vector<pair<int, int>> addr{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int cantFish = 0;

    while (q.size() > 0) {
        auto [_row, _col] = q.front();
        q.pop();

        cantFish += grid[_row][_col];

        for (int i = 0; i < addr.size(); ++i) {
            int newRow = _row + addr.at(i).first;
            int newCol = _col + addr.at(i).second;

            if (isValid(grid, newRow, newCol, visited)) {
                q.emplace(newRow, newCol);
                visited[newRow][newCol] = 1;
            }
        }
    }

    return cantFish;
}

int findMaxFish(matrix<int>& grid) {
    matrix<int> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int maxFish = INT_MIN;

    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid.at(row).size(); ++col) {
            if (visited[row][col] == 0 && grid[row][col] != 0) {
                maxFish = max(maxFish, BFS(grid, visited, row, col));
            }
        }
    }

    return (maxFish == INT_MIN) ? 0: maxFish;
}

int main() {
    matrix<int> grid(2);
    grid[0] = {8, 6};
    grid[1] = {2, 6};
    

    cout << findMaxFish(grid);

    return 0;
}