#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

bool evaluateTree(TreeNode* root) {
    if(root-> val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    if(root-> val == 3) {
        return evaluateTree(root->left) && evaluateTree(root->right);
    }

    return root->val;
}

int main(){
    TreeNode* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);
    root->right->left = createNode(0);
    root->right->right = createNode(1);
    cout<<evaluateTree(root);

    return 0;
}
