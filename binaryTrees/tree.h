#include<iostream>

using namespace std;


struct Node{
    int key;
    Node* left, *right;
};

Node* createNode(int key){
    Node* tmp = new Node;
    tmp->key = key;
    tmp->left = tmp->right = nullptr;
    return tmp;
}


void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);

}

void preOrder(Node* root){
    if(!root)
        return;

    cout<<root->key;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->key;
}


