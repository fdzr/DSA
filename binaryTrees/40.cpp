#include "../common/tree.h"

using namespace Tree;

int findIndex(const vector<int> &preorder, const int &l, const int &r) {
    int idx = -1;

    for (int i = l; i <= r; ++i) {
        if (preorder[i] > preorder[l]) {
            idx = i;
            break;
        }
    }

    return idx;
}

TreeNode<int> *insert(const vector<int> &preorder, int l, int r) {
    if (l > r)
        return nullptr;

    int index = findIndex(preorder, l, r);
    TreeNode<int> *node = createNode(preorder[l]);

    if (l == r) {
        return node;
    }

    int newRight = (index == -1) ? r : index - 1;
    int newLeft = (index == -1) ? r + 1 : newRight + 1;

    node->left = insert(preorder, l + 1, newRight);
    node->right = insert(preorder, newLeft, r);

    return node;
}

TreeNode<int> *bstFromPreorder(vector<int> &preorder) {
    TreeNode<int> *root = insert(preorder, 0, preorder.size() - 1);
    inOrder(root);
    return root;
}

int main() {
    TreeNode<int> *root = createNode(8);
    root->left = createNode(5);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(7);
    root->right->right = createNode(12);

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    bstFromPreorder(preorder);

    return 0;
}