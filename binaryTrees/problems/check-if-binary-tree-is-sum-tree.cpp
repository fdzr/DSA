#include "../../common/tree.h"

using namespace Tree;

int sum(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return root->val + sum(root->left) + sum(root->right);
}

bool isSumTree(TreeNode *root) {
    if (root == nullptr || isLeaf(root)) {
        return true;
    }

    bool answerLeft = isSumTree(root->left);
    bool answerRight = isSumTree(root->right);

    if (answerLeft == false || answerRight == false) {
        return false;
    }

    int sumL = sum(root->left), sumR = sum(root->right);

    return sumL + sumR == root->val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    TreeNode *root = createNode(26);
    root->left = createNode(10);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(6);

    root->right->right = createNode(3);

    cout << boolalpha << isSumTree(root);

    return 0;
}