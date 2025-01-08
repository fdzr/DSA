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
            curr = curr->child[ch - 'a'];
        } else {
            curr = curr->child[ch - 'a'];
        }
    }

    curr->wordEnd = true;

}

int main() { 
    string_view key = "and";
    TrieNode *root = new TrieNode();

    insertKey(root, key);

    return 0; 
}