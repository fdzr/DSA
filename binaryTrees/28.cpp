//
// Created by fzamora on 12-01-23.
//
#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

string tree2str(TreeNode* root) {
    if(!root)
        return "";

    return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(4);
    root->right = createNode(3);

    cout<<tree2str(root);

    return 0;
}


