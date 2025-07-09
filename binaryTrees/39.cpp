#include "../common/tree.h"

using namespace Tree;

void dfs(TreeNode<int> *root, int &sum, TreeNode<int> *parent, TreeNode<int> *grandpa) {
    if (root == nullptr)
        return;

    if (grandpa != nullptr && (grandpa->val & 1) == 0)
        sum += root->val;

    dfs(root->left, sum, root, parent);
    dfs(root->right, sum, root, parent);
}

int sumEvenGrandparent(TreeNode<int> *root) {
    int sum = 0;
    dfs(root, sum, nullptr, nullptr);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode<int> *root = createNode(6);
    root->left = createNode(7);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->left->left->left = createNode(9);
    root->left->right->left = createNode(1);
    root->left->right->right = createNode(4);
    root->right->left = createNode(1);
    root->right->right = createNode(3);
    root->right->right->right = createNode(5);

    cout<< sumEvenGrandparent(root);

    return 0;
}