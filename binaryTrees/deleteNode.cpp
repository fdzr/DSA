#include<iostream>
#include<queue>
#include "tree.h"

using namespace std;


void inorder(Node* root){
    if(!root)
        return;

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void deleteDeepestNode(Node* root, Node* delete_node){
    queue<Node*> q;
    Node* tmp;

    q.push(root);

    while(!q.empty()){
        tmp = q.front();
        q.pop();

        if(tmp == delete_node){
            tmp = nullptr;
            delete delete_node;
            return;
        }
        
        if(tmp->right){
            if(tmp->right == delete_node){
                tmp->right = nullptr;
                delete delete_node;
                return;
            }
            else
                q.push(tmp->right);

        }
        if(tmp->left){
            if(tmp->left == delete_node){
                tmp->left = nullptr;
                delete delete_node;
                return;
            }
            else
                q.push(tmp->left);
        }
    }
}


Node* deletion(Node* root, int key){
    queue<Node*> q;
    Node* tmp = nullptr;
    Node* key_node;

    q.push(root);

    while(!q.empty()){
        tmp = q.front();
        q.pop();
        
        if(tmp->key == key)
            key_node = tmp;
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }

    if(key_node != nullptr){
        int value = tmp->key;
        deleteDeepestNode(root, tmp);
        key_node->key = value;
    }
    return root;
}


int main(){
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->left->right = createNode(12);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout<<endl;
    inorder(root);

    return 0;
}
