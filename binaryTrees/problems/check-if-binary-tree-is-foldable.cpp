#include "../../common/tree.h"

// https://www.geeksforgeeks.org/foldable-binary-trees/#expected-approach-3-using-breadth-first-search-on-time-and-on-space

using namespace Tree;

bool isFoldable(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;

    if (root1 == nullptr || root2 == nullptr) return false;


    return isFoldable(root1->left, root2->right) && isFoldable(root1->right, root2->left);
}

bool solution(TreeNode* root) {
    return (root == nullptr) ? true : isFoldable(root->left, root->right);
}

int main() {
    TreeNode* root = createNode(10);
    // root->left = createNode(7);
    // root->right = createNode(15);
    // root->left->right = createNode(9);
    // root->right->left = createNode(11);

    root->left = createNode(7);
    root->right = createNode(15);
    root->left->left = createNode(5);
    root->right->left = createNode(11);

    cout << boolalpha << solution(root);

    

    return 0;
}