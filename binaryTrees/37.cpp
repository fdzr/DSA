#include "../common/tree.h"

using namespace Tree;

int findDiameter(TreeNode<int>* root, int& cont) {
    if (root == nullptr) return 0;

    int solLeft = findDiameter(root->left, cont);
    int solRight = findDiameter(root->right, cont);

    cont = max(cont, solLeft + solRight);

    return max(solLeft, solRight) + 1;
}

int solution(TreeNode<int>* root) {
    int cont = 0;
    findDiameter(root, cont);
    return cont;
}

int main() {
    TreeNode<int>* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->left->left = createNode(5);
    root->left->left->right = createNode(6);

    root->left->left->left->left = createNode(7);
    root->left->left->right->left = createNode(8);

    cout << solution(root);

    return 0;
}