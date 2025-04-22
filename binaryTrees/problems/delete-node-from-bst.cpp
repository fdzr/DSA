#include "../../common/tree.h"

using namespace Tree;

TreeNode *findInorderSuccesor(TreeNode *root) {
    TreeNode *curr = root;
    while (curr->left) curr = curr->left;

    return curr;
}

TreeNode *findParent(TreeNode *root, TreeNode *node) {
    TreeNode *curr = root;
    TreeNode *parent = nullptr;

    while (curr) {
        if (curr->val == node->val) {
            return parent;
        }

        parent = curr;

        if (node->val > curr->val) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    return parent;
}

void deleteNodeBST(TreeNode *root, int key) {
    TreeNode *curr = root, *parent = nullptr;

    while (curr != nullptr && curr->val != key) {
        parent = curr;

        if (curr->val > key) {
            curr = curr->left;
        } else
            curr = curr->right;
    }

    if (curr == nullptr) return;

    auto replaceChild = [&](TreeNode *child) {
        if (!parent) return;

        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
    };

    if (isLeaf(curr)) {
        replaceChild(nullptr);
        delete curr;
    }

    else if (!curr->left || !curr->right) {
        TreeNode *child = curr->left ? curr->left : curr->right;
        replaceChild(child);
        delete curr;
    }

    else {
        TreeNode *inorderSuccesor = findInorderSuccesor(curr->right);
        TreeNode *succesorParent = findParent(root, inorderSuccesor);

        curr->val = inorderSuccesor->val;

        if (succesorParent->left == inorderSuccesor)
            succesorParent->left = inorderSuccesor->right;
        else
            succesorParent->right = inorderSuccesor->right;

        delete inorderSuccesor;
    }
}

int main() {
    TreeNode *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);

    // root->left->left = createNode(20);
    // root->left->right = createNode(40);

    root->right->left = createNode(60);
    root->right->right = createNode(80);

    root->right->right->left = createNode(75);
    root->right->right->left->right = createNode(76);

    // root->right->left->left = createNode(58);
    // root->right->left->right = createNode(63);

    // root->right->right->left = createNode(75);
    // root->right->right->right = createNode(82);

    // TreeNode *root = createNode(50);
    // root->left = createNode(30);
    // root->right = createNode(70);

    // root->right->left = createNode(60);
    // root->right->right = createNode(80);

    // root->right->right->right = createNode(81);

    inOrder(root);
    cout << "\n";
    deleteNodeBST(root, 70);
    cout << "\n";
    inOrder(root);

    return 0;
}