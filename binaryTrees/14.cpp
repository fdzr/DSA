#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


bool checkTree(Node* root) {
    return (root->key ==  root->left->key + root->right->key);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(4);
    root->right = createNode(6);

    cout<<checkTree(root);


    return 0;
}


