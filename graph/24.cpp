#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Matrix = vector<vector<T>>;

bool isValid(const Matrix<char> &G, const Matrix<int> &visited, int row, int col) {
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() &&
           visited[row][col] == 0;
}

bool DFS(Matrix<char> &G, Matrix<int> &visited, int row, int col, string temp,
         string word) {
    temp += G[row][col];
    visited[row][col] = 1;

    if (temp == word) return true;

    vector<pair<int, int>> directions = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
                                         {0, 1},  {1, 1},   {1, 0},  {1, -1}};

    for (const auto &coor : directions) {
        int newRow = row + coor.first;
        int newCol = col + coor.second;

        if (isValid(G, visited, newRow, newCol) &&
            DFS(G, visited, newRow, newCol, temp, word) == true)
            return true;
    }

    visited[row][col] = 0;
    return false;
}

vector<string> findWord(Matrix<char> &G, const vector<string> &dictionary) {
    vector<string> answer;

    for (const auto &word : dictionary) {
        Matrix<int> visited(G.size(), vector<int>(G[0].size(), 0));

        for (int row = 0; row < G.size(); ++row) {
            for (int col = 0; col < G[row].size(); ++col) {
                if (G[row][col] == word[0] && visited[row][col] == 0) {
                    if (DFS(G, visited, row, col, string(""), word))
                        answer.push_back(word);
                }
            }
        }
    }

    return answer;
}

int main() {
    Matrix<char> boggle = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    for (const auto &word : findWord(boggle, dictionary)) cout << word << "\n";

    return 0;
}