#include "../../common/tree.h"

// https://www.geeksforgeeks.org/dsa/second-largest-element-in-binary-search-tree-bst/

using namespace Tree;

void findSecondLargestElement(TreeNode<int> *root, int &cont, int &number) {
    if (root == nullptr || cont == 0) {
        return;
    }

    findSecondLargestElement(root->right, cont, number);
    if (cont-- > 0) {
        number = root->val;
    }

    findSecondLargestElement(root->left, cont, number);
}

int main() {
    TreeNode<int> *root = createNode(7);
    root->right = createNode(15);
    root->right->left = createNode(9);
    root->right->left->left = createNode(8);
    root->right->left->right = createNode(11);
    root->right->left->right->left = createNode(10);
    root->right->left->right->right = createNode(12);

    int number = 0;
    int cont = 2;

    findSecondLargestElement(root, cont, number);

    printf("%d\n", number);
    
    return 0; 
}