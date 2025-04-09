#include "../../common/tree.h"

using namespace Tree;

bool find_ancestors(TreeNode *root, int node) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == node) {
        return true;
    }

    bool ansL = find_ancestors(root->left, node);
    bool ansR = find_ancestors(root->right, node);

    if (ansL || ansR) {
        cout << root->val << "\n";
    }

    return ansL || ansR;
}

int main() { 
    TreeNode * root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);

    root->left->left = createNode(8);
    root->left->right = createNode(12);

    root->right->left = createNode(16);
    root->right->right = createNode(25);

    root->right->left->left = createNode(18);

    find_ancestors(root, 8);

    return 0;
}