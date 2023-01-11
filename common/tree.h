#include<iostream>
using namespace std;


#ifndef TREE_H
#define TREE_H

namespace Tree {

    struct TreeNode {
        int val;
        TreeNode * left, *right;
    };

    // class for n-ary trees
    class Node {
        public:
            int val;
            vector<Node*> children;

            Node() {}
            Node(int val_): val{val_}{}
            Node(int val_, vector<Node*> _children): val{val_}, children(_children) {}
    };

    TreeNode* createNode(int key){
        TreeNode* tmp = new TreeNode;
        tmp->val = key;
        tmp->left = tmp->right = nullptr;
        return tmp;
    }

    int isLeaf(TreeNode* node){
        if(node == nullptr)
            return 0;
        if(node->left == nullptr && node->right == nullptr)
            return 1;
        return 0;
    }

    void preOrder(TreeNode* root) {
        if (!root)
            return;

        std::cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode* root) {
        if (!root) 
            return;

        inOrder(root->left);
        std::cout<<root->val<<" ";
        inOrder(root->right);
    }

    void postOrder(TreeNode* root) {
        if(!root)
            return;

        postOrder(root->left);
        postOrder(root->right);
        std::cout<<root->val<<" ";
    }

    void searchKey(TreeNode* root, int key, TreeNode* &parent) {
        if (!root)
            return;
        
        if (root->val == key) {
            if (!parent)
                cout<<"key founded! "<<key;
            else if (parent->left && parent->left->val == key)
                cout<<"the key is the node left";
            else if(parent->right && parent->right->val == key)
                cout<<"the key is the node right";

            return;
        }

        if (key < root->val){
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