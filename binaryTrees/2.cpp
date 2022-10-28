#include <iostream>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void search(Node* root, int key) {
    if (!root) return;
    if (root->key == key)
        cout<<"found it "<<root->key;

    if (key < root->key) 
        ::search(root->left, key);
    else 
        ::search(root->right, key);

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

    ::search(root, 19);


    return 0;
}