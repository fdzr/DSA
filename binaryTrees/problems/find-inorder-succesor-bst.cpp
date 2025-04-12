#include "../../common/tree.h"

using namespace Tree;

TreeNode *leftMost(TreeNode *node) {
    TreeNode *curr = node;
    while (curr->left) {
        curr = curr->left;
    }

    return curr;
}

TreeNode *getSuccesor(TreeNode *root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root != nullptr && root->val == key) {
        return leftMost(root->right);
    }

    TreeNode *curr = root, *succesor = nullptr;

    while (curr != nullptr) {
        if (curr->val > key) {
            succesor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return succesor;
}

int main() {
    TreeNode *root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);

    root->left->left = createNode(4);
    root->left->right = createNode(12);

    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);

    auto ptr = getSuccesor(root, 10);

    if (ptr != nullptr) {
        cout << ptr->val;
    } else {
        cout << "no succesor ...";
    }

    return 0;
}