#include<iostream>

using namespace std;


struct Node{
    int key;
    Node* left, *right;
};


void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);

}
