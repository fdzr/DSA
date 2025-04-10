#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

void dfs(Matrix<int> &board, vector<int> &visited, int source) {
    visited[source] = 1;

    cout << source << " ";

    for (int u = 0; u < board[source].size(); ++u) {
        if (board[source][u] == 1 && visited[u] == 0) {
            dfs(board, visited, u);
        }
    }
}

void bfs(Matrix<int> &board, int source) {
    vector<int> visited(board.size(), 0);
    visited[source] = 1;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v = 0; v < board[u].size(); ++v) {
            if (board[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    Matrix<int> board(4, vector<int>(4, 0));

    board[0] = {0, 1, 1, 0};
    board[1] = {1, 0, 1, 1};
    board[2] = {1, 1, 0, 0};
    board[3] = {0, 1, 1, 0};

    vector<int> visited(board.size(), 0);

    dfs(board, visited, 0);
    cout << "\n";

    bfs(board, 0);

    return 0;
}