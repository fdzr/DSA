#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void aux(TreeNode* root, int low, int high, int &sum) {
    if(!root)
        return;

    if(root->val >= low && root->val <= high)
        sum += root->val;

    aux(root->left, low, high, sum);
    aux(root->right, low, high, sum);
}

int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    aux(root, low, high, sum);
    return sum;
}


int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(18);

    cout<<rangeSumBST(root, 7, 15);

    return 0;
}