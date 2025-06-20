#include "../../common/tree.h"

// https://www.geeksforgeeks.org/dsa/check-binary-tree-contains-duplicate-subtrees-size-2/

using namespace Tree;

string generateSubTreesCodified(TreeNode<char> *root, unordered_map<string, int> &um) {
    if (root == nullptr) {
        return "N";
    }

    if (isLeaf(root)) {
        return to_string(root->val);
    }

    string solLeft = generateSubTreesCodified(root->left, um);
    string solRight = generateSubTreesCodified(root->right, um);

    string temp;

    temp.append(to_string(root->val));
    temp.append("*");
    temp.append(solLeft);
    temp.append("*");
    temp.append(solRight);

    um[temp]++;

    return temp;
}

bool solution(TreeNode<char> *root) { 
    unordered_map<string, int> um;
    generateSubTreesCodified(root, um);

    for(auto &item: um) {
        if (item.second > 1)
            return true;
    }


    return false; 
}

int main() {
    TreeNode<char>*root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->right = createNode('B');
    root->right->right->left = createNode('D');
    root->right->right->right = createNode('E');

    inOrder(root);
    cout<<'\n';

    cout<< boolalpha << solution(root);

    return 0; 
}