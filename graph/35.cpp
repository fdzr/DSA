#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

bool isValid(const Matrix &graph, const Matrix &visited, int row, int col) {
    return row >= 0 && row < graph.size() && col >= 0 && col < graph[0].size() &&
           visited[row][col] == 0 && graph[row][col] == 1;
}

bool hasValues(const pair<int, int> &item) {
    return item.first != -1 && item.second != -1;
}

pair<int, int> bfs(Matrix &graph, Matrix &visited, int row, int col) {
    pair<int, int> solution = make_pair(-1, -1);

    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    visited[row][col] = 1;

    while (!q.empty()) {
        auto coor = q.front();
        q.pop();

        for (const auto &coordinates :
             initializer_list<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
            int newRow = coor.first + coordinates.first;
            int newCol = coor.second + coordinates.second;

            if (isValid(graph, visited, newRow, newCol)) {
                pair<int, int> temp = make_pair(newRow, newCol);
                if (!hasValues(solution))
                    solution = temp;
                else {
                    if (temp > solution) solution = temp;
                }

                q.push(make_pair(newRow, newCol));
                visited[newRow][newCol] = 1;
            }
        }
    }

    return solution;
}

vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    if (land.size() == 1 && land[0].size() == 1 && land[0][0] == 0)
        return {};


    Matrix visited(land.size(), vector<int>(land[0].size(), 0));
    Matrix solution;

    for (int row = 0; row < land.size(); ++row) {
        for (int col = 0; col < land[0].size(); ++col) {
            if (land[row][col] == 1 && visited[row][col] == 0) {
                auto temp = bfs(land, visited, row, col);
                if (hasValues(temp))
                    solution.push_back({row, col, temp.first, temp.second});
                else
                    solution.push_back({row, col, row, col});
            }
        }
    }

    return solution;
}

int main() {
    Matrix graph(1);
    graph[0] = {0};
    // graph[1] = {1, 1};
    // graph[2] = {0, 1, 1};

    auto solution = findFarmland(graph);

    for (int row = 0; row < solution.size(); ++row) {
        for (int col = 0; col < solution[row].size(); ++col) {
            cout << solution[row][col] << " ";
        }

        cout << "\n";
    }

    return 0;
}