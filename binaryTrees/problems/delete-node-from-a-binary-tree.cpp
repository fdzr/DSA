#include "../../common/tree.h"

// https://www.geeksforgeeks.org/deletion-binary-tree/

using namespace Tree;

void deleteDeepestNode(TreeNode* root, TreeNode* deleteNode) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr = nullptr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->left) {
            if (curr->left == deleteNode) {
                curr->left = nullptr;
                delete curr->left;
                return;
            }

            q.push(curr->left);
        }

        if (curr->right) {
            if (curr->right == deleteNode) {
                curr->right = nullptr;
                delete curr->right;
                return;
            }

            q.push(curr->right);
        }
    }
}

void deleteNode(TreeNode* root, int key) {
    queue<TreeNode*> q;
    TreeNode *curr = nullptr, *nodeToBeDeleted = nullptr;
    q.push(root);

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->val == key) {
            nodeToBeDeleted = curr;
        }
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }

    if (nodeToBeDeleted != nullptr) {
        int x = curr->val;
        nodeToBeDeleted->val = x;
        deleteDeepestNode(root, curr);
    }
}

int main() {
    TreeNode* root = createNode(13);
    root->left = createNode(12);
    root->right = createNode(10);

    root->left->left = createNode(4);
    root->left->right = createNode(19);

    root->right->left = createNode(16);
    root->right->right = createNode(9);

    preOrder(root);
    cout<< "\n";

    deleteNode(root, 12);
    preOrder(root);

    return 0;
}