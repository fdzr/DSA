#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

int maxDepth(Node* root) {
    int cont = 0;
    queue<Node*> cola;

    if(!root)
        return cont;

    cola.push(root);
    cola.push(nullptr);

    while(!cola.empty()) {
        Node* node = cola.front();
        cola.pop();

        if(node == nullptr) {
            cont++;
            continue;
        }

        for(auto child: node->children) {
            cola.push(child);
        }

        if(cola.front() == nullptr)
            cola.push(nullptr);
    }

    return --cont;
}


int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    cout<< maxDepth(root);


    return 0;
}