#include <bits/stdc++.h>

using namespace std;

template <typename T>
using board = vector<vector<T>>;

bool isValid(const board<char> &boogle, board<int> &visited, int row, int col) {
    return row >= 0 && row < boogle.size() && col >= 0 && col < boogle[0].size() &&
           visited[row][col] == 0;
}

void maxPath(const board<char> &boogle, board<int> &visited, int row, int col, int cont,
             int &maxCont, char previousCH) {
    visited[row][col] = 1;
    char currentCH = boogle[row][col];

    if (previousCH != ' ' && previousCH + 1 != currentCH) {
        maxCont = max(maxCont, cont);
        return;
    }

    if (previousCH != ' ' && previousCH + 1 == currentCH) {
        cont += 1;
    }

    vector<pair<int, int>> directions = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},
    };

    for (const auto &addr : directions) {
        int newRow = row + addr.first;
        int newCol = col + addr.second;

        if (isValid(boogle, visited, newRow, newCol)) {
            maxPath(boogle, visited, newRow, newCol, cont, maxCont, boogle[row][col]);
            visited[newRow][newCol] = 0;
        }
    }

    
}

int main() {
    board<char> boogle = {{'D', 'E', 'H', 'X', 'B'},
                          {'A', 'O', 'G', 'P', 'E'},
                          {'D', 'D', 'C', 'F', 'D'},
                          {'E', 'B', 'E', 'A', 'S'},
                          {'C', 'D', 'Y', 'E', 'N'}};
    char previousChar = ' ';
    int cont = 1;
    int maxCont = 0;
    board<int> visited(boogle.size(), vector<int>(boogle[0].size(), 0));

    maxPath(boogle, visited, 2, 2, cont, maxCont, previousChar);

    cout<<maxCont;

    return 0;
}