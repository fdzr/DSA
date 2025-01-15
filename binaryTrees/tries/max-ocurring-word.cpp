#include "trie.hpp"

using namespace std;
using namespace trie;

// https://www.techiedelight.com/find-maximum-occurring-word-given-set-strings/

void maxOccuringWord(TrieNode *root, int &maxOccur, string &preffix, string path) {
    if (root == nullptr) return;

    if (root->isWord) {
        TrieNodeWithCount *nodeWithCount = dynamic_cast<TrieNodeWithCount *>(root);
        if (nodeWithCount != nullptr) {
            if (nodeWithCount->count > maxOccur) {
                maxOccur = nodeWithCount->count;
                preffix = path;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (root->child[i] != nullptr) {
            maxOccuringWord(root->child[i], maxOccur, preffix,
                            path + static_cast<char>(i + 'a'));
        }
    }
}

int main() {
    vector<string> words = {
        "code",   "coder",        "coding",  "codable", "codec",        "codecs",
        "coded",  "codeless",     "codec",   "codecs",  "codependence", "codex",
        "codify", "codependents", "codes",   "code",    "coder",        "codesign",
        "codec",  "codeveloper",  "codrive", "codec",   "codecs",       "codiscovered"};

    TrieNode *root = new TrieNodeWithCount();

    for (const auto &word : words) insertKeyWithCount(root, word);

    int maxOccur = 0;
    string preffix = "";
    maxOccuringWord(root, maxOccur, preffix, "");

    cout << maxOccur << ": "<<preffix;

    return 0;
}