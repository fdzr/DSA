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

bool isEmpty(TrieNode* root) {
    for (const auto& item : root->child)
        if (item != nullptr) return false;

    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth = 0) {
    if (!root) return nullptr;

    if (depth == key.size()) {
        if (root->wordEnd) root->wordEnd = false;

        if (isEmpty(root)) {
            delete root;
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->child[index] = remove(root->child[index], key, depth + 1);

    if (isEmpty(root) && root->wordEnd == false) {
        delete root;
        root = nullptr;
    }

    return root;
}

int main() {
    vector<string> keys = {"and", "ant", "do", "geek", "dad", "ball"};
    TrieNode* root = new TrieNode();

    for (const string& s : keys) {
        insertKey(root, s);
    }

    vector<string> searchKeys = {"do", "gee", "bat"};

    for (const auto& sk : searchKeys) {
        if (search(root, sk)) {
            cout << sk << " is in the trie" << "\n";
        } else {
            cout << sk << " is not in the trie" << "\n";
        }
    }

    cout << "\n";
    delete root;
    root = new TrieNode();

    keys = {"the", "a",   "there", "answer", "any",
            "by",  "bye", "their", "hero",   "heroplane"};

    for (int i = 0; i < keys.size(); i++) insertKey(root, keys[i]);

    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";

    remove(root, "heroplane");
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";

    return 0;
}