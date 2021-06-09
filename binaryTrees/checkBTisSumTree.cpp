#include <iostream>
#include "tree.h"

using namespace std;

int isSumTree(Node* node){
    int ls, rs;
    
    if(node == nullptr || isLeaf(node))
        return 1;

    if(isSumTree(node->left) && isSumTree(node->right)){
        if(node->left == nullptr)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->key;
        else
            ls = 2 * (node->left->key);


        if(node->right == nullptr)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->key;
        else
            rs = 2 * (node->right->key);



        return (node->key == ls + rs);

    }
    return 0;
}


int main(){
    Node *root = createNode(26);
    root->left = createNode(10);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(6);
    root->right->right = createNode(3);
    if(isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}
