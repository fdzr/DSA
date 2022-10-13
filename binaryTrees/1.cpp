#include<iostream>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

Node* insert(Node* root, int key) {
    if(!root) {
        return createNode(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    // if (key < tree->key && !tree->left) {
    //     tree->left = createNode(key);
    //     return;
    // }

    // if (key > tree->key && !tree->right) {
    //     tree->right = createNode(key);
    //     return;
    // }   
    return root;

}

int main() {
    Node* root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);
    root->left->left = createNode(8);
    root->left->right = createNode(12);
    root->right->left = createNode(18);
    root->right->right = createNode(25);
    root->right->left->right = createNode(19);
    root->right->right->right = createNode(30);

    preOrder(root);
    cout<<endl;
    insert(root, 24);
    preOrder(root);

    return 0;
}