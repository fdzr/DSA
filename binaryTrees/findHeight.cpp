#include <iostream>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


int maxDepth(TreeNode* root){
    if(!root)
        return 0;

    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    if(lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}


int main(){
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Height of tree is " << maxDepth(root) - 1;

    return 0;
}


