#include <bits/stdc++.h>

#include "../common/tree.h"

using namespace std;
using namespace Tree;

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

int convert(TreeNode<int>* root, int value) {
    if (root == nullptr) {
        return value;
    }

    int rightValue = convert(root->right, value);
    root->val += rightValue;
    int leftValue = convert(root->left, root->val);

    return leftValue;
}

TreeNode<int>* bstToGst(TreeNode<int>* root) {
    convert(root, 0);
    return root;
}

int main() {
    TreeNode<int>* root = createNode(4);
    root->left = createNode(1);
    root->right = createNode(6);
    root->left->left = createNode(0);
    root->left->right = createNode(2);
    root->left->right->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    root->right->right->right = createNode(8);

    bstToGst(root);

    inOrder(root);

    return 0;
}