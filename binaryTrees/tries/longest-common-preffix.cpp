#include <bits/stdc++.h>

#include "trie.hpp"

using namespace std;
using namespace trie;

int getNumberChildren(TrieNode* root) {
    int cont = 0;
    for (const auto& child : root->child) {
        if (child != nullptr) ++cont;
    }

    return cont;
}

string preOrder(TrieNode* root, string& preffix) {
    int numberOfChildren = getNumberChildren(root);
    if (numberOfChildren != 0 && numberOfChildren != 1) return preffix;
    if (root->isWord) return preffix;

    for (int i = 0; i < 26; ++i) {
        if (root->child[i] != nullptr) {
            preffix.push_back(static_cast<char>(i + 'a'));
            return preOrder(root->child[i], preffix);
        }
    }

    return preffix;
}

string LCP(TrieNode* root) {
    string preffix = "";

    preOrder(root, preffix);

    return preffix;
}

int main() {
    vector<string> keys = {"codable", "code", "coder", "coding"};

    TrieNode* root = new TrieNode();

    for (const auto& word : keys) insertKey(root, word);

    cout << LCP(root);

    return 0;
}