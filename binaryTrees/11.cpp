#include <iostream>
#include <queue>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void invertTree(Node* root) {
    if(!root)
        return;

    invertTree(root->left);
    invertTree(root->right);

    int tmp = root->key;
}

Node* invertTree_2(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node *tmp = q.front(), *aux;
        q.pop();

        aux = tmp->left;
        tmp->left = tmp->right;
        tmp->right = aux;

        if(tmp->left)
            q.push(tmp->left);

        if(tmp->right)
            q.push(tmp->right);


    }

    return root;

}


int main() {
    // Node *root = createNode(1);
    // root->right = createNode(3);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    

    // root->left = createNode(2);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);

    Node * root = createNode(1);
    // root->left = createNode(2);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);

    root->right = createNode(2);
    // root->right->right = createNode(6);

    Node* tt = invertTree_2(root);
    preOrder(root);

    return 0;
}