//
// Created by fzamora on 12-01-23.
//
#include "bits/stdc++.h"
#include "../common/tree.h"

using namespace std;
using namespace Tree;

using vi = vector<int>;

void DFS(TreeNode* root, vi &leaves) {
    if(!root)
        return;

    if(!root->left && !root->right)
        leaves.push_back(root->val);

    DFS(root->left, leaves);
    DFS(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vi leaves1, leaves2;

    DFS(root1, leaves1);
    DFS(root2, leaves2);

    if(leaves1.size() != leaves2.size())
        return false;

    return leaves1 == leaves2;
}


int main() {


    return 0;
}