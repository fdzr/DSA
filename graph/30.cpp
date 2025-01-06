#include <bits/stdc++.h>

using namespace std;

template <typename T>
using board = vector<vector<T>>;

vector<pair<int, int>> directions = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool isValid(const board<char> &boogle, int row, int col, const board<int> &visited) {
    return row >= 0 && row < boogle.size() && col >= 0 && col < boogle[0].size() &&
           visited[row][col] == 0;
}

bool dfs(const board<char> &boogle, board<int> &visited, int row, int col, int index,
         const string &word) {
    if (index == word.size()) {
        return true;
    }

    visited[row][col] = 1;

    for (const auto &addr : directions) {
        int newRow = row + addr.first;
        int newCol = col + addr.second;

        if (isValid(boogle, newRow, newCol, visited) && boogle[newRow][newCol] == word[index]) {
            index += 1;
            if (dfs(boogle, visited, newRow, newCol, index, word)) return true;

            index -= 1;
        }
    }

    visited[row][col] = 0;

    return false;
}

void generateAllWordsAndFind(const board<char> &boogle, board<int> &visited, int row, int col,
                             string path, const unordered_set<string> &dict) {
    visited[row][col] = 1;

    path.push_back(boogle[row][col]);

    if (dict.find(path) != dict.end()) {
        // if repeated characters, it can be found repeated words
        cout << path << "\n";
    }

    for (const auto &addr : directions) {
        int newRow = row + addr.first;
        int newCol = col + addr.second;

        if (isValid(boogle, newRow, newCol, visited))
            generateAllWordsAndFind(boogle, visited, newRow, newCol, path, dict);
    }

    visited[row][col] = 0;
}

void findWordsII(vector<string> &dict, const board<char> &boogle) {
    unordered_set<string> dictOp(dict.begin(), dict.end());

    for (int row = 0; row < boogle.size(); ++row) {
        for (int col = 0; col < boogle[row].size(); ++col) {
            board<int> visited(boogle.size(), vector<int>(boogle[0].size(), 0));
            generateAllWordsAndFind(boogle, visited, row, col, "", dictOp);
        }
    }
}

void findWords(vector<string> &dict, const board<char> &boogle) {
    for (const auto &word : dict) {
        board<int> visited(boogle.size(), vector<int>(boogle[0].size(), 0));

        for (int row = 0; row < boogle.size(); ++row) {
            for (int col = 0; col < boogle[row].size(); ++col) {
                if (boogle[row][col] == word[0] && dfs(boogle, visited, row, col, 1, word)) {
                    cout << word << "\n";
                }
            }
        }
    }
}

int main() {
    board<char> boogle = {
        {'M', 'S', 'E', 'F'},
        {'R', 'A', 'T', 'D'},
        {'L', 'O', 'N', 'E'},
        {'K', 'F', 'B', 'A'}};
    vector<string> dict = {"START", "NOTE", "SAND", "STONED"};

    // findWords(dict, boogle);
    findWordsII(dict, boogle);

    return 0;
}