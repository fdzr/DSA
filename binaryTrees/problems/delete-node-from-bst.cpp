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
    TreeNode *curr = root, *temp = nullptr;

    while (curr != nullptr) {
        if (curr->val == key) {
            if (isLeaf(curr)) {
                if (temp->left->val == key) {
                    delete curr;
                    temp->left = nullptr;
                } else {
                    delete curr;
                    temp->right = nullptr;
                }

                return;

            } else {
                if (curr->left == nullptr && curr->right != nullptr) {
                    if (temp->left->val == key) {
                        temp->left = curr->right;
                        delete curr;
                    } else {
                        temp->right = curr->right;
                        delete curr;
                    }

                    return;

                } else if (curr->left != nullptr && curr->right == nullptr) {
                    if (temp->left->val == key) {
                        temp->left = curr->left;
                        delete curr;
                    } else {
                        temp->left = curr->left;
                        delete curr;
                    }

                    return;

                } else {
                    TreeNode *succesor = findInorderSuccesor(curr->right);
                    TreeNode *parent = findParent(root, succesor);

                    if (parent->left->val == succesor->val) {
                        parent->left = nullptr;

                    } else
                        parent->right = nullptr;

                    if (temp->left->val == curr->val) {
                        temp->left->val = succesor->val;
                    } else {
                        temp->right->val = succesor->val;
                    }

                    return;
                }
            }
        }

        temp = curr;

        if (curr->val > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

int main() {
    TreeNode *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);

    root->left->left = createNode(20);
    root->left->right = createNode(40);

    root->right->left = createNode(60);
    root->right->right = createNode(80);

    root->right->left->left = createNode(58);
    root->right->left->right = createNode(63);

    root->right->right->left = createNode(75);
    root->right->right->right = createNode(82);

    inOrder(root);

    // preOrder(root);
    cout << "\n";
    deleteNodeBST(root, 70);
    cout << "\n";
    inOrder(root);

    return 0;
}