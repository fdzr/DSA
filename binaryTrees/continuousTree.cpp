#include "tree.h"

#include<iostream>
#include<cstdlib>
using namespace std;


bool continuousTree(Node* root){

    if(!root)
        return true;

    if(!root->left && !root->right)
        return true;
    
    if(root->left == nullptr)
        return abs(root->key - root->right->key)==1 && 
                continuousTree(root->right);

    if(root->right == nullptr)
        return abs(root->key - root->left->key) ==1 &&
                continuousTree(root->left);

    return abs(root->key - root->left->key) == 1 &&
            abs(root->key - root->right->key) == 1 &&
            continuousTree(root->left) && continuousTree(root->right);
}

int main(){
    Node* root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->right = createNode(5);

    continuousTree(root)? cout<<"Yes": cout<<"No";

    return 0;
}
