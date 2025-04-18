#include "../common/tree.h"

using namespace Tree;

pair<int, int> solution(TreeNode *root, int &cont) {
    if (root ==nullptr) {
        return make_pair(0, 0);
    }

    auto solLeft = solution(root->left, cont);
    auto solRight = solution(root->right, cont);

    int cantNodes = solLeft.second + solRight.second + 1;
    int sumNodes = solLeft.first + solRight.first + root->val;

    if(sumNodes / cantNodes == root->val) cont +=1;

    return make_pair(sumNodes, cantNodes);
}


int averageOfSubtree(TreeNode* root) {
    int cont = 0;

    solution(root, cont);

    return cont;
        
}

int main() {
    TreeNode *root = createNode(1);
    root->left = createNode(8);
    root->right = createNode(5);
    root->left->left = createNode(0);
    root->left->right = createNode(1);
    root->right->right = createNode(6);

    cout << averageOfSubtree(root);

    return 0;
}