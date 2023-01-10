//
// Created by fzamora on 10-01-23.
//
#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

using vs = vector<string>;

void DFS(TreeNode* root, vs &numbers, string cad) {
   if(!root) {
        return;
    }

    cad += to_string(root->val);
    if(!root->left && !root->right)
        numbers.push_back(cad);

    DFS(root->left, numbers, cad);
    DFS(root->right, numbers, cad);
}

int sumRootToLeaf(TreeNode* root) {
    vs ans;
    int sum = 0;
    DFS(root, ans, "");

    for(auto number: ans) {
        bitset<64> bits(number);
        sum += bits.to_ulong();
    }

    return static_cast<int>(sum);
}


int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(0);
    root->left->left = createNode(0);
    root->left->right = createNode(1);

    root->right = createNode(1);
    root->right->left = createNode(0);
    root->right->right = createNode(1);

    cout<<sumRootToLeaf(root);

    return 0;
}