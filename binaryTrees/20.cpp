#include <bits/stdc++.h>
#include "../common/tree.h"

using namespace std;
using namespace Tree;

bool helper(TreeNode* reference, TreeNode* target) {
    if(!reference)
        return true;

    return reference->val == target->val && 
           helper(reference->left, target->left) && 
           helper(reference->right, target->right);
}

void postOrder(TreeNode* root, TreeNode* target, TreeNode* & ans) {
    if(!root)
        return;

    if(root->val == target->val) {
        if(helper(root, target))
            ans = root;
    }

    postOrder(root->left, target, ans);
    postOrder(root->right, target, ans);

}


TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(!original)
        return nullptr;

    TreeNode* ans = nullptr;
    postOrder(cloned, target, ans);


    return ans;
}


int main() {
    TreeNode *root_1 = createNode(3);
    root_1->left = createNode(2);
    root_1->right = createNode(4);
    
    TreeNode *root_2 = createNode(3);
    root_2->left = createNode(2);
    root_2->right = createNode(4);
    cout<<helper(root_1, root_2);

    return 0;
}