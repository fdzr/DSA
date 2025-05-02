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

TreeNode *decodeTree(string &cad, vector<int> &arr, int &indexCad, int &indexVector) {
    if (cad[indexCad] == '0') {
        ++indexCad;
        return nullptr;
    }

    TreeNode *root = createNode(arr[indexVector++]);
    ++indexCad;

    root->left = decodeTree(cad, arr, indexCad, indexVector);
    root->right = decodeTree(cad, arr, indexCad, indexVector);

    return root;
}

int main() {
    TreeNode *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->right->right = createNode(40);

    string cad = "";
    vector<int> arr;

    encodeTree(root, cad, arr);
    cout << cad << "\n";

    int indexCad = 0;
    int indexVector = 0;
    TreeNode *newRoot = decodeTree(cad, arr, indexCad, indexVector);
    preOrder(newRoot);

    return 0;
}