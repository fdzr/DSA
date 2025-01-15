#include "trie.hpp"

using namespace trie;

void preOrder(TrieNode *root, std::string word) {
    if(root == nullptr)
        return;

    bool printWord = false;

    for(int i = 0; i < 26; ++i) {
        if(root->isWord == true && printWord == false){
            std::cout<<word<<"\n";
            printWord = true;
        } 
        if(root->child[i] != nullptr) {
            // if(root->isWord) std::cout<< word<< "\n";
            preOrder(root->child[i], word + char(i + 'a'));
        }
    }
}

int main() {
    TrieNode *root = new TrieNode();

    std::string keys[] = {
        "lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
        "be", "accomplished", "with", "a", "simple", "trie", "based",
        "algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
        "output", "all", "keys", "in", "the", "trie", "by", "means", "of",
        "preorder", "traversal", "which", "results", "in", "output", "that",
        "is", "in", "lexicographically", "increasing", "order", "preorder",
        "traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
    };

    for(const auto & k: keys)
        insertKey(root, k);

    preOrder(root, "");
    

    return 0;
}