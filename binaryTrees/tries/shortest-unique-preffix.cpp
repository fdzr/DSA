#include <bits/stdc++.h>
// https://www.techiedelight.com/shortest-unique-prefix/

#define ALPHABET 26

using namespace std;

class Trie {
   public:
    Trie *child[ALPHABET];
    bool isLeaf;
    int frequency;

    Trie() {
        isLeaf = false;
        frequency = 0;
        for (int i = 0; i < ALPHABET; ++i) {
            child[i] = nullptr;
        }
    }
};

void insertKey(Trie *root, string key) {
    Trie *curr = root;

    for (const auto &ch : key) {
        if (curr->child[ch - 'A'] == nullptr) {
            curr->child[ch - 'A'] = new Trie();
            curr->child[ch - 'A']->frequency = 1;
        } else {
            curr->child[ch - 'A']->frequency += 1;
        }

        curr = curr->child[ch - 'A'];
    }
}

string searchKey(Trie *root, string key) {
    Trie *curr = root;
    string preffix = "";

    for (const auto &ch : key) {
        preffix += ch;

        if (curr->child[ch - 'A']->frequency == 1) {
            return preffix;
        } else {
            curr = curr->child[ch - 'A'];
        }
    }

    return preffix;
}

int main() {
    vector<string> words = {"AND", "BONFIRE", "BOOL", "CASE", "CATCH", "CHAR"};

    Trie *root = new Trie();
    for(const auto &word: words) insertKey(root, word);

    for(const auto&word: words) {
        printf("%s : %s\n", word.c_str(), searchKey(root, word).c_str());
    }

    return 0;
}