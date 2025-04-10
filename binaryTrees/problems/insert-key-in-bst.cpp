#include "../../common/tree.h"

using namespace Tree;

TreeNode* insertKey(TreeNode* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if(root->val > key) {
        root->left = insertKey(root->left, key);
    } else {
        root->right = insertKey(root->right, key);
    }

    return root;
}

int main() {
    TreeNode* root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);

    root->left->left = createNode(8);
    root->left->right = createNode(12);

    root->right->right = createNode(25);

    int key = 16;

    root = insertKey(root, key);

    preOrder(root);

    return 0;
}