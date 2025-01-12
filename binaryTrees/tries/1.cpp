#include <bits/stdc++.h>

using namespace std;

class TrieNode {
   public:
    TrieNode* child[26];
    bool wordEnd;

    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode* root, const string_view& key) {
    TrieNode* curr = root;

    for (const auto& ch : key) {
        if (curr->child[ch - 'a'] == nullptr) {
            curr->child[ch - 'a'] = new TrieNode();
        }
        curr = curr->child[ch - 'a'];
    }

    curr->wordEnd = true;
}

bool search(TrieNode* root, const string_view& key) {
    TrieNode* curr = root;
    if (curr == nullptr) return false;

    for (const auto& ch : key) {
        if (curr->child[ch - 'a'] == nullptr) return false;

        curr = curr->child[ch - 'a'];
    }

    return curr->wordEnd;
}

int main() {
    vector<string> keys = {"and", "ant", "go", "geek", "dad", "ball"};
    TrieNode* root = new TrieNode();

    for (const string& s : keys) {
        insertKey(root, s);
    }

    return 0;
}