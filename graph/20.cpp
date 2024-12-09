#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

void BFS(Matrix<char> G, Matrix<int>& visited, int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        auto coor = q.front();
        q.pop();

        visited[coor.first][coor.second] = 1;

        if (coor.second - 1 >= 0 && visited[coor.first][coor.second - 1] == 0 &&
            G[coor.first][coor.second - 1] == 'X')
            q.push({coor.first, coor.second - 1});

        if (coor.first - 1 >= 0 && visited[coor.first - 1][coor.second] == 0 &&
            G[coor.first - 1][coor.second] == 'X')
            q.push({coor.first - 1, coor.second});

        if (coor.second + 1 < G[0].size() && visited[coor.first][coor.second + 1] == 0 &&
            G[coor.first][coor.second + 1] == 'X')
            q.push({coor.first, coor.second + 1});

        if (coor.first + 1 < G.size() && visited[coor.first + 1][coor.second] == 0 &&
            G[coor.first + 1][coor.second] == 'X')
            q.push({coor.first + 1, coor.second});
    }
}

int countBattleships(vector<vector<char>>& board) {
    Matrix<int> visited(board.size(), vector<int>(board[0].size(), 0));
    int battleShip = 0;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if(visited[i][j] == 0 && board[i][j] == 'X') {
                ++battleShip;
                BFS(board, visited, i, j);
            }
        }
    }

    return battleShip;
}

int main() {
    Matrix<char> G(3);
    G[0] = {'X','.','.','X'};
    G[1] = {'.','.','.','X'};
    G[2] = {'.','.','.','X'};

    printf("%d\n", countBattleships(G));

    G.resize(1);
    G[0] = {'.'};

    printf("%d\n", countBattleships(G));


    return 0;
}