#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;


void inOrder(TreeNode* root, vector<int> &elems) {
    if(root == nullptr)
        return;

    inOrder(root->left, elems);

    if(root)
        elems.push_back(root->val);

    inOrder(root->right, elems);
}

int getMinimumDifference(TreeNode* root) {
    vector<int> elems;
    inOrder(root, elems);

    int min_value = INT_MAX;
    for(int i = 1; i < elems.size(); ++i)
        min_value = min(min_value, abs(elems[i] - elems[i - 1]));

    return min_value;
}



int main() {
    TreeNode* root = createNode(4);
    root->left=createNode(2);
    root->right=createNode(6);
    root->left->left=createNode(1);
    root->left->right=createNode(3);

    cout<<getMinimumDifference(root);
    
    // preOrder(root);
    // cout<<"\n";

    // inOrder(root);
    // cout<<"\n";
    // postOrder(root);
    // cout<<"\n";
    


    return 0;
}