#include <bits/stdc++.h>
// https://www.techiedelight.com/print-all-pairs-of-anagrams/

#define ALPHABET 26

using namespace std;

class Trie {
   public:
    Trie *child[ALPHABET];
    bool isLeaf;
    vector<string> words;

    Trie() {
        isLeaf = false;

        for (int i = 0; i < ALPHABET; ++i) {
            child[i] = nullptr;
        }
    }
};

void insertKey(Trie *root, const string &key) {
    Trie *curr = root;
    string copyKey = key;
    sort(copyKey.begin(), copyKey.end());

    for (const auto &ch : copyKey) {
        if (curr->child[ch - 'a'] == nullptr) {
            curr->child[ch - 'a'] = new Trie();
        }

        curr = curr->child[ch - 'a'];
    }

    curr->isLeaf = true;
    curr->words.push_back(key);
}

void preOrder(Trie *root) {
    if (root == nullptr) return;

    if (root->isLeaf && root->words.size() > 1) {
        copy(root->words.begin(), root->words.end(), ostream_iterator<string>(cout, " "));
        cout<<"\n";
    }

    for (int i = 0; i < ALPHABET; ++i) {
        if (root->child[i] != nullptr) {
            preOrder(root->child[i]);
        }
    }
}

void printPairs(const vector<pair<string, string>> &ans) {
    for (const auto &[first, second] : ans) {
        cout << "(" << first << ", " << second << ")";
        cout << "\n";
    }
}

void groupAnagrams(Trie *root, const vector<string> &dict) {
    for (const auto &word : dict) insertKey(root, word);

    preOrder(root);
}

int main() {
    Trie *root = new Trie();
    vector<string> words = {"auctioned", "actors",  "altered", "streaming", "related",
                            "education", "aspired", "costar",  "despair",   "mastering"};

    groupAnagrams(root, words);

    return 0;
}