#include <bits/stdc++.h>

// https://www.techiedelight.com/find-all-words-matching-pattern-dictionary/

using namespace std;

class Trie {
   public:
    Trie *child[26];
    unordered_set<string> words;

    Trie() {
        for (int i = 0; i < 26; ++i) child[i] = nullptr;
    }
};

void insertKey(Trie *root, string key) {
    Trie *curr = root;
    for (const auto &ch : key) {
        if (isupper(ch)) {
            if (curr->child[ch - 'A'] == nullptr) {
                curr->child[ch - 'A'] = new Trie();
            }

            curr = curr->child[ch - 'A'];
        }
    }

    curr->words.insert(key);
}

Trie *search(Trie *root, string key) {
    Trie *curr = root;

    for (const auto &ch : key) {
        if (curr->child[ch - 'A'] == nullptr) {
            return nullptr;
        }
        curr = curr->child[ch - 'A'];
    }

    return curr;
}

void preOrder(Trie *root, unordered_set<string> &answer) {
    if (root == nullptr) return;

    if (root->words.size() > 0) {
        answer.insert(root->words.begin(), root->words.end());
    }

    for (int i = 0; i < 26; ++i) {
        if (root->child[i] != nullptr) {
            preOrder(root->child[i], answer);
        }
    }
}

void showWords(const unordered_set<string> &words) {
    if (words.size() == 0) {
        printf("No words founded ...");
    }

    for (const auto &word : words) {
        printf("%s ", word.c_str());
    }

    printf("\n");
}

int main() {
    string dict[] = {"Hi", "HiTech", "HiTechCity", "Hello", "HelloWorld", "HiTechLab"};
    string patterns[] = {"HT", "HTC", "H"};

    Trie *root = new Trie();
    for (const auto &w : dict) insertKey(root, w);

    for (const auto &p : patterns) {
        auto curr = search(root, p);
        unordered_set<string> ans;
        preOrder(curr, ans);
        showWords(ans);
    }

    return 0;
}