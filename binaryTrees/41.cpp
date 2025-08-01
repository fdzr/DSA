#include "../common/tree.h"

using namespace Tree;

void solution(TreeNode<int> *root, string &cad, string &answer) {
    if (root == nullptr) {
        return;
    }

    cad += static_cast<char>(root->val + 97);

    if (root->left == nullptr && root->right == nullptr) {
        reverse(cad.begin(), cad.end());
        answer = (answer == "") ? cad : min(cad, answer);
        reverse(cad.begin(), cad.end());
    }

    solution(root->left, cad, answer);
    solution(root->right, cad, answer);

    cad.pop_back();
}

string smallestFromLeaf(TreeNode<int> *root) {
    string answer = "", temp = "";
    solution(root, temp, answer);

    return answer;
}

int main() {
    TreeNode<int> *root = createNode(2);
    root->left = createNode(2);
    root->right = createNode(1);

    root->left->right = createNode(1);
    root->left->right->left = createNode(0);

    root->right->left = createNode(0);

    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(0);
    root->right->right = createNode(2);

    cout << smallestFromLeaf(root);

    return 0;
}