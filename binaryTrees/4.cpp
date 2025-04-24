#include "../common/tree.h"

using namespace Tree;

bool isSameTree(TreeNode *tree_1, TreeNode *tree_2) {
    if (tree_1 == nullptr && tree_2 == nullptr)
        return true;

    if (tree_1 == nullptr || tree_2 == nullptr)
        return false;

    if (tree_1->val != tree_2->val)
        return false;

    return isSameTree(tree_1->left, tree_2->left) &&
           isSameTree(tree_1->right, tree_2->right);
}

int main() {
    TreeNode *tree_1 = createNode(1);
    tree_1->left = createNode(2);
    tree_1->right = createNode(3);

    TreeNode *tree_2 = createNode(1);
    tree_2->left = createNode(2);
    tree_2->right = createNode(3);

    cout << boolalpha << isSameTree(tree_1, tree_2);

    return 0;
}