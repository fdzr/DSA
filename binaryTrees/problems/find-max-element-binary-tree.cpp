#include "../../common/tree.h"

// https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

using namespace Tree;

int findMaxValue(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int solLeft = findMaxValue(root->left);
    int solRight = findMaxValue(root->right);

    int currentValue = root->val;
    int maxValue = (solLeft > solRight) ? solLeft : solRight;
    maxValue = (currentValue > maxValue) ? currentValue : maxValue;

    return maxValue;
}

int main() {
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(7);

    root->right->left = createNode(5);
    root->right->right = createNode(6);

    root->right->left->left = createNode(8);
    root->right->left->right = createNode(9);

    cout << findMaxValue(root);

    return 0;
}