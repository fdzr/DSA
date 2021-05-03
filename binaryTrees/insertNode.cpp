#include<iostream>
#include<queue>
#include "tree.h"

using namespace std;


Node* insertNode(Node* root, int value){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* tmp = q.front();
        q.pop();

        if(tmp->left)
            q.push(tmp->left);
        else{
            tmp->left = createNode(value);
            return root;
        }

        if(tmp->right)
            q.push(tmp->right);
        else{
            tmp->right = createNode(value);
            return root;
        }
    }
    return root;
}

int main(){
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    inOrder(root);
    cout<<endl;

    root = insertNode(root, 12);
    inOrder(root);
    cout<<endl;

    return 0;
}
