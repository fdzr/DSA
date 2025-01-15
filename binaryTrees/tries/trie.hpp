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

    virtual ~TrieNode() = default;
};

class TrieNodeWithCount : public TrieNode {
   public:
    int count;
    TrieNodeWithCount() : TrieNode() { count = 0; }
};

void insertKeyWithCount(TrieNode *root, std::string key) {
    TrieNode *curr = root;
    for (const auto &ch : key) {
        if (curr->child[ch - 'a'] == nullptr) {
            curr->child[ch - 'a'] = new TrieNodeWithCount();
        }

        curr = curr->child[ch - 'a'];
    }

    curr->isWord = true;
    TrieNodeWithCount *newCurr = dynamic_cast<TrieNodeWithCount *>(curr);
    if (newCurr != nullptr) {
        newCurr->count++;
    } else {
        throw std::runtime_error("Error in implementation...");
    }
}

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