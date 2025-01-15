#include <bits/stdc++.h>

namespace trie {

class TrieNode {
   public:
    TrieNode *child[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode *root, std::string key) {
    TrieNode *curr = root;
    for (const auto &ch : key) {
        if (curr->child[ch - 'a'] == nullptr) {
            curr->child[ch - 'a'] = new TrieNode();
        }

        curr = curr->child[ch - 'a'];
    }

    curr->isWord = true;
}

bool search(TrieNode *root, std::string key) {
    TrieNode *curr = root;

    for (const auto &ch : key) {
        if (curr->child[ch - 'a'] == nullptr) return false;
        curr = curr->child[ch - 'a'];
    }

    return curr->isWord;
}

};  // namespace trie