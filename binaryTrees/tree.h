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


