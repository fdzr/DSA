//
// Created by fzamora on 10-01-23.
//
#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

vector<double> averageOfLevels(TreeNode* root) {
    int cont = 0;
    double sum = 0.0;
    vector<double> ans;
    queue<TreeNode*> cola;
    cola.push(root);
    cola.push(nullptr);

    while(!cola.empty()) {
        auto node = cola.front();
        cola.pop();
        if(node == nullptr) {
            ans.push_back(static_cast<double>(sum / cont));
            cont = 0;
            sum = 0.0;
            if(cola.empty())
                break;

            cola.push(nullptr);
            continue;
        }

        sum += node->val;
        cont++;

        if(node->left)
            cola.push(node->left);

        if(node->right)
            cola.push(node->right);


    }

    return ans;
}


int main() {
    TreeNode* root = createNode(15);

    root->left = createNode(13);
    root->left->left = createNode(9);
    root->left->right = createNode(10);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(2);
    root->left->right->left = createNode(3);
    root->left->right->right = createNode(4);

    root->right = createNode(14);
    root->right->left = createNode(11);
    root->right->right = createNode(12);
    root->right->left->left = createNode(5);
    root->right->left->right = createNode(6);
    root->right->right->left = createNode(7);
    root->right->right->right = createNode(8);

//    preOrder(root);
    for(auto elem: averageOfLevels(root))
        cout<<elem<<" ";

    return 0;
}