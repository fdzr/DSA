#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


int countNodes(TreeNode* root) {
    if(root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    cout<<countNodes(root);

    return 0;
}