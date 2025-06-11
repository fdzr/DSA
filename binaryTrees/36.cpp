#include "../common/tree.h"

using namespace Tree;

int solution(TreeNode* root, int& cont) {
    if (root == nullptr)
        return 0;

    int solLeft = solution(root->left, cont);
    int solRight = solution(root->right, cont);

    int tempSolLeft = 0;
    if (root->left && root->left->val == root->val)
        tempSolLeft = solLeft + 1;
    
    int tempSolRight = 0;
    if (root->right && root->right->val == root->val)
        tempSolRight = solRight + 1;
    
    cont = max(cont, tempSolLeft + tempSolRight);

    return max(tempSolLeft, tempSolRight);

}

int longestUnivaluePath(TreeNode* root) {
    int cont = 0;
    solution(root, cont);
    return cont;
}

int main() {
    TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(1);
    root->right->right = createNode(1);

    cout << longestUnivaluePath(root);

    return 0;
}