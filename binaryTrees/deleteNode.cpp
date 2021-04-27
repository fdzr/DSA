#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

struct Node* newNode(int key){
    Node * tmp = new Node;
    tmp->key=key;
    tmp->left = tmp->right = nullptr;
    return tmp;
}

int main(){
    return 0;
}
