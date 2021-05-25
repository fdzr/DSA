#include <iostream>
#include "tree.h"

using namespace std;


int maxDepth(Node* root){
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
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Height of tree is " << maxDepth(root);

    return 0;
}


