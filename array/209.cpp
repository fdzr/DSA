#include <bits/stdc++.h>

using namespace std;

template <typename T>
using MATRIX = vector<vector<T>>;

vector<pair<int, int>> coordinates = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(const MATRIX<char>& m, MATRIX<bool>& visited, int row, int col,
         string tempWord, const string& target, int index) {
    if (tempWord == target) {
        return true;
    }

    for (const auto& [r, c] : coordinates) {
        int newRow = row + r;
        int newCol = col + c;

        bool isValidRow = newRow >= 0 && newRow < m.size();
        bool isValidCol = newCol >= 0 && newCol < m[0].size();

        if (isValidRow && isValidCol && target[++index] == m[newRow][newCol]) {
            tempWord.push_back(m[newRow][newCol]);

            if (dfs(m, visited, newRow, newCol, tempWord, target, index)) {
                return true;
            }
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board[row].size(); ++col) {
            if (board[row][col] == word[0]) {
                MATRIX<bool> visited(board.size(),
                                     vector<bool>(board[0].size(), false));
                string tempWord = "";

                if (dfs(board, visited, row, col, tempWord, word, 0))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    MATRIX<char> m = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };
    string target = "SEE";

    cout<< boolalpha<<exist(m, target) << '\n';

    return 0;
}