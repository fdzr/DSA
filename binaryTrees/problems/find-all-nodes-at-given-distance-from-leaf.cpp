#include "../../common/tree.h"

// https://www.techiedelight.com/find-all-nodes-at-given-distance-from-leaf-nodes-in-a-binary-tree/

using namespace Tree;

void findNodes(TreeNode *root, int dist, vector<TreeNode *> ancestors,
               unordered_set<TreeNode *> &conj) {
    if (root == nullptr) {
        return;
    }

    if (isLeaf(root) && ancestors.size() >= dist) {
        conj.insert(ancestors[ancestors.size() - dist]);
        return;
    }

    ancestors.push_back(root);

    findNodes(root->left, dist, ancestors, conj);
    findNodes(root->right, dist, ancestors, conj);
}

void solution(TreeNode *root, int dist) {
    unordered_set<TreeNode *> conj;
    vector<TreeNode *> ancestors;

    findNodes(root, dist, ancestors, conj);

    for (const auto &node : conj) {
        cout << node->val << "\n";
    }
}

int main() {
    TreeNode *root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);

    root->left->left = createNode(8);
    root->left->right = createNode(12);

    root->right->left = createNode(16);
    root->right->right = createNode(25);

    root->right->left->left = createNode(18);

    int dist = 1;
    solution(root, dist);

    return 0;
}