#include "../../common/tree.h"

using namespace Tree;

void encodeTree(TreeNode *root, string &cad, vector<int> &arr) {
    if (root == nullptr) {
        cad.push_back('0');
        return;
    }

    cad.push_back('1');
    arr.push_back(root->val);

    encodeTree(root->left, cad, arr);
    encodeTree(root->right, cad, arr);
}

int main() { 
    TreeNode *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->right->right = createNode(40);

    string cad = "";
    vector<int> arr;

    encodeTree(root, cad, arr);
    cout<<cad;


    return 0;
}