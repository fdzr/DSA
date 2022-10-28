#include<iostream>
using namespace std;


#ifndef TREE_H
#define TREE_H

namespace Tree {

    struct Node {
        int key;
        Node * left, *right;
    };

    Node* createNode(int key){
        Node* tmp = new Node;
        tmp->key = key;
        tmp->left = tmp->right = nullptr;
        return tmp;
    }

    int isLeaf(Node* node){
        if(node == nullptr)
            return 0;
        if(node->left == nullptr && node->right == nullptr)
            return 1;
        return 0;
    }

    void preOrder(Node* root) {
        if (!root)
            return;

        std::cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) {
        if (!root) 
            return;

        inOrder(root->left);
        std::cout<<root->key<<" ";
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if(!root)
            return;

        postOrder(root->left);
        postOrder(root->right);
        std::cout<<root->key<<" ";
    }

    void searchKey(Node* root, int key, Node* &parent) {
        if (!root)
            return;
        
        if (root->key == key) {
            if (!parent) {
                cout<<"key founded! "<<key;
            }
            else if (parent->left && parent->left->key == key)
                cout<<"the key is the node left";
            else if(parent->right && parent->right->key == key)
                cout<<"the key is the node right";

            return;
        }

        if (key < root->key){
            parent = root;
            searchKey(root->left, key, parent);
        }
        else {
            parent = root;
            searchKey(root->right, key, parent);
        }
            
    }

};

#endif