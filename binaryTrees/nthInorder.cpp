#include <iostream>
#include "tree.h"

using namespace std;


void nthInorder(Node* root, int n){
    if(!root)
        return;

    static int count = 0;

    if(count <= n){
        nthInorder(root->left, n);
        count++;
        
        if(count == n){
            cout<<root->key;
            return;
        }
        nthInorder(root->right, n);
    }
}


int main(){
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    nthInorder(root, 4);


    return 0;
}
