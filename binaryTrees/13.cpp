#include <iostream>
#include <vector>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


void sumLeavesLeft(Node *root, int &sum) {
    if(!root)
        return;

    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->key;

    sumLeavesLeft(root->left, sum);
    sumLeavesLeft(root->right, sum);

}

int main() {
    Node *root = createNode(1);
    root->right = createNode(3);
    root->right->left = createNode(6);
    // root->right->right = createNode(7);

    // root->left = createNode(2);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);

    int sum = 0;
    sumLeavesLeft(root, sum);
    cout<<sum;


    return 0;
}