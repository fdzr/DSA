#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void DFS(TreeNode* &root1, TreeNode* root2, TreeNode* prev, char pos) {
    if(!root1 && !root2)
        return;

    if (root1 && root2) {
        root1->val += root2->val;
        prev = root1;
        DFS(root1->left, root2->left, prev, 'l');
        DFS(root1->right, root2->right, prev, 'r');
    }

    if(!root1 && root2) {
        if(pos == ' ')
            root1 = root2; 
        else if(pos == 'l')
            prev->left = root2;
        else 
            prev->right = root2;
    }
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    DFS(root1, root2, nullptr, ' ');
    return root1;
}


int main() {
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    // root1->right->left = createNode(4);
    // root1->right->right = createNode(5);

    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->left->left = createNode(3);
    // root2->left->left->left = createNode(6);
    root2->left->right = createNode(4);
    root2->right = createNode(5);
    root2->right->right = createNode(6);
    root2->right->right->left = createNode(8);

    DFS(root1, root2, nullptr, ' ');
    preOrder(root1);
    

    return 0;
}