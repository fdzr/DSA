#include <bits/stdc++.h>

#include "../common/tree.h"

using namespace std;
using namespace Tree;

bool search(TreeNode *root, int key) {
    if(root == nullptr) return false;
    if(root->val == key) return true;

    cout<<root->val<< " ";
    bool leftSearch = search(root->left, key);
    bool rightSearch = search(root->right, key);

    return leftSearch || rightSearch;
}

int main() {
    TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(8);
    root->left->left = createNode(10);
    root->left->right = createNode(11);
    root->left->right->left = createNode(6);
    root->left->right->right = createNode(15);
    root->right->left = createNode(2);
    root->right->right = createNode(1);

    preOrder(root);

    cout<<"\n";

    cout<< boolalpha << search(root, 15);

    return 0;
}