/* Print nodes of a perfect binary tree such as, print nodes from the left node 
 * in the respective level and the right node alternatively, from bottom - up.
 * source: https://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal-set-2/
 *
 * */


#include <iostream>
#include <stack>
#include <queue>
#include "tree.h"

using namespace std;


void preprocessing(Node* root, stack<Node*> &s){
    if(!root)
        return;

    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);

    Node *first = nullptr, *second = nullptr;

    while(!q.empty()){
        first = q.front();
        q.pop();
        second = q.front();
        q.pop();

        s.push(second->left);
        s.push(first->right);
        s.push(second->right);
        s.push(first->left);

        if(first->left->left != nullptr){
            q.push(first->right);
            q.push(second->left);
            q.push(first->left);
            q.push(second->right);
        }
    }
}


void printSpecificLevelOrder(Node* root){
   stack<Node*> s;
   s.push(root);

   if(root->left){
        s.push(root->left);
        s.push(root->right);
   }

   if(root->left->left)
       preprocessing(root, s);

   while(!s.empty()){
        cout<<s.top()->key<<" ";
        s.pop();
   }
}
    

int main(){
    Node* root = createNode(1);    

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);
    root->right->left  = createNode(6);
    root->right->right = createNode(7);
 
    root->left->left->left  = createNode(8);
    root->left->left->right  = createNode(9);
    root->left->right->left  = createNode(10);
    root->left->right->right  = createNode(11);
    root->right->left->left  = createNode(12);
    root->right->left->right  = createNode(13);
    root->right->right->left  = createNode(14);
    root->right->right->right  = createNode(15);
 
    root->left->left->left->left  = createNode(16);
    root->left->left->left->right  = createNode(17);
    root->left->left->right->left  = createNode(18);
    root->left->left->right->right  = createNode(19);
    root->left->right->left->left  = createNode(20);
    root->left->right->left->right  = createNode(21);
    root->left->right->right->left  = createNode(22);
    root->left->right->right->right  = createNode(23);
    root->right->left->left->left  = createNode(24);
    root->right->left->left->right  = createNode(25);
    root->right->left->right->left  = createNode(26);
    root->right->left->right->right  = createNode(27);
    root->right->right->left->left  = createNode(28);
    root->right->right->left->right  = createNode(29);
    root->right->right->right->left  = createNode(30);
    root->right->right->right->right  = createNode(31);

    cout<<"Specific Level Order traversal ob binary tree is \n";
    printSpecificLevelOrder(root);
    

   

}
