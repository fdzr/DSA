#include <bits/stdc++.h>

// binary matrix
// https://www.techiedelight.com/find-duplicate-rows-binary-matrix/

using namespace std;

class Trie {
   public:
    Trie *children[2];
    bool isLeaf;

    Trie() {
        isLeaf = false;
        for (int i = 0; i < 2; ++i) children[i] = nullptr;
    }
};

bool insert(Trie *root, vector<int> row) {
    Trie *curr = root;

    for (int i = 0; i < row.size(); ++i) {
        if (curr->children[row[i]] == nullptr) {
            curr->children[row[i]] = new Trie();
        }

        curr = curr->children[row[i]];
    }

    if (curr->isLeaf == true) return false;

    curr->isLeaf = true;

    return true;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  0,  0,  1,  0},
        {0,  1,  1,  0,  0},
        {1,  0,  0,  1,  0},
        {0,  0,  1,  1,  0},
        {0,  1,  1,  0,  0,}
    };

    Trie *root = new Trie();

    for(int row = 0; row < matrix.size(); ++row) {
        if(!::insert(root, matrix[row])) {
            printf("%d\n", row + 1);
        }
    }

    return 0;
}