#include<iostream>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void insert(Node* tree, int key) {
    if(!tree) {

        return;
    }

    if (key < tree->key)
        insert(tree->left, key);
    else
        insert(tree->right, key);

    if (key < tree->key && !tree->left) {
        tree->left = createNode(key);
        return;
    }

    if (key > tree->key && !tree->right) {
        tree->right = createNode(key);
        return;
    }   


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
    insert(root, 16);
    preOrder(root);

    return 0;
}