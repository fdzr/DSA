#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

using vi = vector<int>;

void DFS(TreeNode* root, vi &nodes) {
    if(!root)
        return;

    DFS(root->left, nodes);
    nodes.push_back(root->val);
    DFS(root->right, nodes);
}


TreeNode* increasingBST(TreeNode* root) {
    vi ans;
    DFS(root, ans);
    TreeNode* aux = createNode(0);
    TreeNode* tmp = aux;

    for(auto elem: ans) {
        
        tmp->right = createNode(elem);
        tmp = tmp->right;
    }
    
    return aux->right;
    
}


int main() {
    TreeNode* root = createNode(8);
    root->left = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(6);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(7);
    
    root->right = createNode(9);
    

    increasingBST(root);
    
   

    return 0;
}