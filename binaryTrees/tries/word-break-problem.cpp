#include <bits/stdc++.h>

#include "trie.hpp"

using namespace std;
using namespace trie;

bool isWordBreakable(TrieNode *root, const string &word) {
    vector<int> preffix(word.size(), 0);
    preffix[0] = 1;
    int n = word.size();

    for (int i = 0; i < n; ++i) {
        if (i == 0 || preffix[i - 1] == 1) {
            TrieNode *curr = root;
            for (int j = i; j < n; ++j) {
                if (curr == nullptr) break;

                curr = curr->child[word[j] - 'a'];
                if (curr && curr->isWord) {
                    preffix[j] = 1;
                }
            }
        }
    }

    return preffix[n - 1];
}

int main() {
    TrieNode *root = new TrieNode();
    string word = "catsandog";
    vector<string> dictionary = {"cats", "dog", "sand", "and", "cat"};

    for (const auto &w : dictionary) insertKey(root, w);

    cout << boolalpha << isWordBreakable(root, word) << "\n";

    return 0;
}