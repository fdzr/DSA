#include<iostream>
#include "tree.h"

using namespace std;

bool isMirror(Node* tree_1, Node* tree_2){
    if(tree_1 == nullptr && tree_2 == nullptr)
        return true;

    if(tree_1->key != tree_2->key)
        return false;

    return isMirror(tree_1->left, tree_2->right) 
            && isMirror(tree_1->right, tree_2->left);
}


int main(){

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    bool answer = isMirror(root->left, root->right);
    answer?cout<<"Tree is a mirror":cout<<"Tree is not a mirror";

    return 0;
}
