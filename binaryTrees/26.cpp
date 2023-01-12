//
// Created by fzamora on 12-01-23.
//

#include "bits/stdc++.h"
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void helper(TreeNode* root, int elem, bool &flag) {
    if(!root)
        return;

    flag = flag & (root->val == elem);
    helper(root->left, elem, flag);
    helper(root->right, elem, flag);
}

bool isUnivalTree(TreeNode* root) {
    int elem = root->val;
    bool flag = true;
    helper(root, elem, flag);

    return flag;
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(10);
    root->left->left = createNode(10);
    root->left->right = createNode(10);

    root->right = createNode(10);
    root->right->left = createNode(10);
    root->right->right = createNode(10);
    cout<<isUnivalTree(root);

    return 0;
}