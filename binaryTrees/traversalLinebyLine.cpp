#include <iostream>
#include <queue>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

void levelOrder(TreeNode* root){
    if(!root)
        return;

    queue<TreeNode *> q;
    TreeNode* tmp;

    q.push(root);
    q.push(nullptr);

    while(q.size() > 1){
        tmp = q.front();
        q.pop();

        if(tmp == nullptr){
            q.push(nullptr);
            cout<<endl;
        }
        else{
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);

            cout<<tmp->val<<" ";
        }
    }
}

int main(){
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    levelOrder(root);

    return 0;
}
