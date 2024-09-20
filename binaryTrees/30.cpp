#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


bool checkPathSum(TreeNode* root, int currentSum, int targetSum) {
    if(root == nullptr) return false;

    currentSum += root->val;

    if (currentSum == targetSum && root->left == nullptr && root->right == nullptr)
        return true;

    bool checkLeft = checkPathSum(root->left, currentSum, targetSum);
    bool checkRight = checkPathSum(root->right, currentSum, targetSum);

    return  checkLeft || checkRight;
}


bool hasPathSum(TreeNode* root, int targetSum) {
    int currentSum = 0;

    return checkPathSum(root, currentSum, targetSum);
}

int main() {
    TreeNode* root = createNode(5);
    root->left = createNode(4);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right = createNode(8);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);

    cout<<boolalpha<<hasPathSum(root, 1);

    return 0;
}